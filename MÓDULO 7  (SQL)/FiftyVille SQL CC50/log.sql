SELECT id,description FROM crime_scene_reports WHERE year = 2020 AND month = 7 AND day = 28 AND street = 'Chamberlin Street';

SELECT id,name,transcript FROM interviews WHERE year = 2020 AND month = 7 AND day = 28;

SELECT id,name,transcript FROM interviews WHERE year = 2020 AND month = 7 AND day = 28 AND transcript LIKE '%courthouse%';

SELECT activity,license_plate FROM courthouse_security_logs WHERE activity = 'exit' AND day = 28 AND month = 7 AND year = 2020 AND hour = 10 AND minute = 25;

SELECT activity,license_plate FROM courthouse_security_logs WHERE day = 28 AND month = 7 AND year = 2020 AND hour = 10 AND minute = 25;

SELECT account_number FROM atm_transactions WHERE atm_location = 'Fifer Street' AND year = 2020 AND month = 7 AND day = 28;

SELECT id,name,phone_number,passport_number,license_plate FROM people WHERE id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE atm_location = 'Fifer Street' AND year = 2020 AND month = 7 AND day = 28 AND transaction_type = 'withdraw'));

SELECT id,hour,minute FROM flights WHERE origin_airport_id = 8 AND year = 2020 AND month = 7 AND day = 29 ORDER BY hour;

SELECT passport_number FROM passengers WHERE flight_id = 36;

SELECT name FROM people WHERE passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 36);

SELECT name FROM people WHERE phone_number IN (SELECT caller FROM phone_calls WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60);

SELECT name FROM people WHERE license_plate IN (SELECT license_plate FROM courthouse_security_logs WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10 AND 15<minute AND minute<25 AND activity = 'exit');

SELECT destination_airport_id FROM flights WHERE id = 36;

SELECT phone_number FROM people WHERE name = 'Ernest';

SELECT receiver FROM phone_calls WHERE day = 28 AND year = 2020 AND month = 7 AND duration <60 AND caller = '(367) 555-5533';

SELECT name FROM people WHERE phone_number = '(375) 555-8161';