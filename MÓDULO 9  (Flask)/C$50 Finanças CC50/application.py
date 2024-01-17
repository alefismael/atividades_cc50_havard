import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True


# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

@app.route("/")
@login_required
def index():

    user_info = db.execute("SELECT * FROM users WHERE id = ?", session["user_id"])
    cash = user_info[0]["cash"]

    rows = db.execute("SELECT * FROM user_stocks WHERE user_id = ?", session["user_id"])

    user_info_actions = []
    total = cash

    if rows:
        for row in rows:
            symbol_info = lookup(row["stock_symbol"])
            quantity = row["quantity"]
            price = symbol_info["price"]
            total += quantity * price

            user_info_actions.append({
                "symbol": row["stock_symbol"],
                "quantity": quantity,
                "price": usd(price),
                "total": usd(quantity * price)
            })

    return render_template("index.html", cash=usd(cash), actions=user_info_actions, total=usd(total))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method == "POST":
        symbol = lookup(request.form.get("symbol"))

        if symbol is None:
            return apology("Error: Invalid symbol", 400)

        try:
            amount = int(request.form.get("amount"))
        except ValueError:
            return apology("Error: Invalid amount", 400)

        if amount <= 0:
            return apology("Error: Number of shares must be positive", 400)

        price = symbol["price"] * amount

        cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]

        if price > cash:
            return apology("Error: Not enough cash to buy", 403)

        cash -= price

        db.execute("INSERT INTO transactions (id_buyer, action, amount, v_purchase, transaction_type) VALUES (?, ?, ?, ?, ?)",
                   session["user_id"], symbol["symbol"], amount, price, 'Purchase')

        row = db.execute("SELECT * FROM user_stocks WHERE user_id = ? AND stock_symbol = ?",
                         session["user_id"], symbol["symbol"])

        if row:
            new_quantity = row[0]["quantity"] + amount
            db.execute("UPDATE user_stocks SET quantity = ? WHERE id = ?", new_quantity, row[0]["id"])

        else:
            db.execute("INSERT INTO user_stocks (user_id, stock_symbol, quantity) VALUES (?, ?, ?)",
                       session["user_id"], symbol["symbol"], amount)

        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash, session["user_id"])

        return redirect("/")

    else:
        return render_template("buy.html")
    


@app.route("/history")
@login_required
def history():
    
    transactions = db.execute(
        "SELECT * FROM transactions WHERE id_buyer = ?", session["user_id"]
    )

    transaction_list = []

    for transaction in transactions:
        symbol = transaction["action"]
        shares = transaction["amount"]
        price = usd(transaction["v_purchase"])
        transaction_type = transaction["transaction_type"]

        transaction_list.append({
            "type": transaction_type,
            "symbol": symbol,
            "shares": shares,
            "price": price,
            "timestamp": transaction["timestamp"]
        })

    transaction_list = sorted(transaction_list, key=lambda x: x["timestamp"])

    return render_template("history.html", transactions=transaction_list)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""

    # If POST method
    if request.method == "POST":
        quote = lookup(request.form.get("quote"))   
        # Checks whether the request is valid
        if quote == None:
            return apology("Error : Query error", 403)

        # Passes the request response to quoted.html
        return render_template("quoted.html", quote=quote)  
        
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # If POST method
    if request.method == "POST":

        #If the user was not informed
        if not request.form.get("username"):
            return apology("Error : not username", 403)
        
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        #If you already have a user with the same name
        if len(rows) == 1 :
            return apology("Error : username is already in use", 403)
        
        #If at least one of the two passwords was not passed
        if not request.form.get("password") or not request.form.get("confirm_password"):
            return apology("Error: password not provided", 403)
        
        #If the two passwords are not the same
        if request.form.get("password") != request.form.get("confirm_password"):
            return apology("Error: different passwords provided", 403)

        password = request.form.get("password")
        hash = generate_password_hash(password)

        #Adding the user to the database
        db.execute("INSERT INTO users (username, hash) VALUES (?,?)", request.form.get("username"),hash)

        return redirect("/login")    
        
    # If not POST method
    else:
        return render_template("register.html")
        
    


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")

        # Validations
        if not symbol:
            return apology("Please select a stock symbol", 400)

        if not shares or not shares.isdigit() or int(shares) <= 0:
            return apology("Please enter a valid number of shares", 400)

        # Get user stocks
        user_stocks = db.execute("SELECT * FROM user_stocks WHERE user_id = ? AND stock_symbol = ?", session["user_id"], symbol)

        # Check if user owns enough shares
        if not user_stocks or user_stocks[0]["quantity"] < int(shares):
            return apology("You don't have enough shares to sell", 400)

        # Get current stock price
        stock_info = lookup(symbol)
        if not stock_info:
            return apology("Error getting stock information", 500)

        stock_price = stock_info["price"]
        total_sale = int(shares) * stock_price

        # Update user cash
        db.execute("UPDATE users SET cash = cash + ? WHERE id = ?", total_sale, session["user_id"])

        # Update user stocks
        new_quantity = user_stocks[0]["quantity"] - int(shares)
        if new_quantity == 0:
            db.execute("DELETE FROM user_stocks WHERE id = ?", user_stocks[0]["id"])
        else:
            db.execute("UPDATE user_stocks SET quantity = ? WHERE id = ?", new_quantity, user_stocks[0]["id"])

        # Record the sale in a transactions/history table if needed

        db.execute("INSERT INTO transactions (id_buyer, action, amount, v_purchase, transaction_type) VALUES (?, ?, ?, ?, 'Sale')",
                   session["user_id"], symbol, int(shares), total_sale)

        # Redirect user to home page
        return redirect("/")

    else:
        # If GET method, render the sell.html
        rows = db.execute("SELECT DISTINCT stock_symbol FROM user_stocks WHERE user_id = ?", session["user_id"])
        return render_template("sell.html", rows=rows)


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)

@app.route("/add_cash", methods=["GET", "POST"])
@login_required
def add_cash():
    if request.method == "POST":
        try:
            amount = float(request.form.get("amount"))
        except ValueError:
            flash("Invalid amount. Please enter a valid number.", "danger")
            return redirect("/add_cash")

        if amount <= 0:
            flash("Amount must be greater than zero.", "danger")
            return redirect("/add_cash")

        # Atualizar saldo do usuário
        db.execute("UPDATE users SET cash = cash + ? WHERE id = ?", amount, session["user_id"])

        flash(f"Successfully added ${amount} to your account.", "success")
        return redirect("/")
    else:
        return render_template("add_cash.html")


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)

if __name__ == '__main__':
    app.run(debug=True)