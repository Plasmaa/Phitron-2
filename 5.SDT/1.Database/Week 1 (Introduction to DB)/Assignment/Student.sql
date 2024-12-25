CREATE DATABASE Assignment_1;

USE Assignment_1;

CREATE TABLE Student (
    Roll CHAR(4),
    Name VARCHAR(100),
    Email VARCHAR(50),
    Address VARCHAR(200),
    Age INT
);

INSERT INTO Student (Roll, Name, Email, Address, Age) 
VALUES ('0001', 'Shaikh Zarif', 'zarif@gmail.com', 'kalabagan, Dhaka', 50);
INSERT INTO Student (Roll, Name, Email, Address, Age) 
VALUES ('0002', 'Mahir Siam', 'Mahirsiam@gmail.com', 'badda, Dhaka', 30);
INSERT INTO Student (Roll, Name, Email, Address, Age) 
VALUES ('0003', 'Ghalib', 'ghalib@gmail.com', 'uttara, Dhaka', 100);

CREATE TABLE Library (
    BookID INT,
    BookName VARCHAR(50),
    Who_Hired_Roll CHAR(4),
    FOREIGN KEY (Who_Hired_Roll) REFERENCES Student(Roll)
);

INSERT INTO Library (BookID, BookName, Who_Hired_Roll)
VALUES (1, 'Data Structures', '0001');
INSERT INTO Library (BookID, BookName, Who_Hired_Roll)
VALUES (2, 'Database Management', '0002');

CREATE TABLE Fees (
    FeeID INT,
    Roll CHAR(4),
    Amount DECIMAL(10, 2),
    FOREIGN KEY (Roll) REFERENCES Student(Roll)
);

INSERT INTO Fees (FeeID, Roll, Amount)
VALUES (1, '0001', 5000.00);
INSERT INTO Fees (FeeID, Roll, Amount)
VALUES (2, '0002', 7000.00);

SET SQL_SAFE_UPDATES = 0;
SET SQL_SAFE_UPDATES = 1;
