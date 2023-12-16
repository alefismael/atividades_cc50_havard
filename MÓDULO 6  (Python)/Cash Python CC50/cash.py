import sys

#Calculadora feita com o objetivo de facilitar a vida do caixa ao dar o troco

#Agora, inciando o programa chamando a função main


print("SEJA VEM VINDO AO TROCO FÁCIL!!")

print("\nEsse programa foi criado para facilitar o troco, informando quantas notas e moedas você precisa dar de troco especificamente.\n")

print("Informe o valor total da compra do cliente:")
print("(exemplo - R$23,42)\nR$",end="")

compra = float(input())

while compra <= 0:
  print("Valor informado inválido, por favor informe um número como valor positivo ou digite 0 para fechar o programa.\nR$",end="")
  compra = float(input())
  if compra == 0:
    sys.exit()


print("\nAgora informe o valor recebido para pagar a compra.")
print("(exemplo - R$23,42)\nR$",end="")

saldo = float(input())

while (saldo <= 0) or (saldo - compra <0):
  print("O valor recebido não é suficiente para pagar a conta, digite 0 para fechar o programa ou então informe outro valor.\nR$",end="")
  saldo = float(input())
  if (saldo == 0):
      sys.exit()


#Feito a conversão, agora a parte final, descobrir o troco que precisa ser dado, e então informar ao usuário as informações.

troco = (saldo-compra)
troc=troco
n100=0
n50=0
n20=0
n10=0
n5=0
n2=0
n1=0
m20=0
m10=0
m5=0
m1=0

while (troc-100)>=0:
  n100+=1
  troc=troc-100

while (troc-50)>=0:
  n50+=1
  troc=troc-50

while (troc-20)>=0:
  n20+=1
  troc=troc-20

while (troc-10)>=0:
  n10+=1
  troc=troc-10

while (troc-5)>=0:
  n5+=1
  troc=troc-5

while (troc-2)>=0:
  n2+=1
  troc=troc-2

while (troc-1)>=0:
  n1+=1
  troc=troc-1

while (troc-0.2)>=0:
  m20+=1
  troc=troc-0.2

while (troc-0.1)>=0:
  m10+=1
  troc=troc-0.1

while (troc-0.05)>=0:
  m5+=1
  troc=troc-0.05

while (troc-0.01)>=0:
  m1+=1
  troc=troc-0.01


print(f"\nO troco é R${troco}",end="")
print("\nSerá necessário para dar esse troco:")
if n100>0:
  print(f"\nNotas de R$100 - {n100}",end="")

if n50>0:
  print(f"\nNotas de R$50 - {n50}",end="")

if n20>0:
  print(f"\nNotas de R$20 - {n20}",end="")

if n10>0:
  print(f"\nNotas de R$10 - {n10}",end="")

if n5>0:
  print(f"\nNotas de R$5 - {n5}",end="")

if n2>0:
  print(f"\nNotas de R$2 - {n2}",end="")

if n1>0:
  print(f"\nNotas de R$1 - {n1}",end="")

if m20>0:
  print(f"\nMoedas de R$0,20 - {m20}",end="")

if m10>0:
  print(f"\nMoedas de R$0,10 - {m10}",end="")

if m5>0:
  print(f"\nMoedas de R$0,05 - {m5}",end="")

if m1>0 :
  print(f"\nMoedas de R$0,01 - {m1}",end="")

print("\n")