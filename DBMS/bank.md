```sql
//bank_db database
CREATE DATABASE bank_db;

//bank table :
CREATE TABLE bank(branch_id int PRIMARY KEY,branch_name varchar(30),branch_city varchar(20));

//account_holder table :
CREATE TABLE account_holder(account_holder_id int PRIMARY KEY,
account_holder_number int,
account_holder_name varchar(20),
account_holder_city varchar(20),
account_holder_contact varchar(20),
account_date date,
account_status varchar(30),
account_type varchar(20),
account_balance decimal(10,2));

//loan table :
CREATE TABLE loan(loan_number int PRIMARY KEY,
branch_id int,
account_holder_id int,
loan_amount decimal(10,2),
loan_type varchar(20),
FOREIGN KEY(branch_id) REFERENCES bank(branch_id),
FOREIGN KEY(account_holder_id) REFERENCES account_holder(account_holder_id));

//Insert Data into Bank Table
INSERT INTO Bank (branch_id, branch_name, branch_city) VALUES
(1,  'SBI', 'rajkot'),
(2, 'Bank of baroda', 'ahemdabad'),
(3,'union','junagadh'),
(4,'kotak','moarbi'),
(5,'SDFC','surat');

//Insert Data into account_holder Table

INSERT INTO account_holder VALUES
(1, 001, 'khushbu', 'junagadh', '9725848599', '2003-10-04', 'active', 'checking', 500.00),
(2, 002, 'kishan', 'rajkot', '9316529039', '1999-08-09', 'active', 'savings', 300.00),
(3, 003, 'janvi', 'ceneda', '9726121012', '2007-05-09', 'active', 'checking', 600.00),
(4, 004,'harsh','ahemdabad','8866929211','2000-11-29','active','saving',700.00);
(5, 005, 'dhvani', 'rajkot', '9316529039', '1999-08-09', 'active', 'current ', 200.00),
(6, 006, 'janvi', 'rajkot', '9726121012', '2007-05-09', 'current ', 'saving', 400.00);

//Insert data into loan table
INSERT INTO loan VALUES(1001,1,4,200000,"multy"),
(1002,5,3,500000,"full"),
(1003,2,6,30000,"quater");



//account A is trying to transfer $100 to account B.
START TRANSACTION;

UPDATE account_holder
SET account_balance = account_balance - 100.00
WHERE account_holder_number = 001;

UPDATE account_holder
SET account_balance = account_balance + 100.00
WHERE account_holder_number = 002;

COMMIT;

//Fetch account holders from the same city:
SELECT * FROM account_holder WHERE account_holder_city = 'rajkot';

//accounts were created after 15th of any month

SELECT account_holder_number, account_holder_name 
FROM account_holder 
WHERE DAY(account_date) > 15;

//Display the city name and count the branches in that city
SELECT branch_city, COUNT(branch_id) AS Count_Branch 
FROM bank 
GROUP BY branch_city;

//Display account holder’s ID, name, branch ID, and loan amount for people who have taken loans (using JOIN):
SELECT A.account_holder_id, A.account_holder_name, L.branch_id, L.loan_amount 
FROM account_holder A
JOIN Loan L ON A.account_holder_id = L.account_holder_id;
```