create database practice;

use practice;

CREATE TABLE Student(
 Roll char(4) PRIMARY KEY,
 Name VARCHAR(100) NOT NULL,
 Email VARCHAR(50),
 Address VARCHAR(200) UNIQUE,
 Age INT CHECK (Age > 10)
);

INSERT INTO Student(Roll, Name, Email, Address, Age) VALUES('0001', 'Shaikh Zarif', 'gg@gmail.com', 'kalabagan, Dhaka', 50);
INSERT INTO Student(Roll, Name, Email, Address, Age) VALUES('0002', 'Mahir Siam', 'Mahirsiam@gmail.com', 'badda, Dhaka', 30);

CREATE TABLE Student(
 Roll char(4),
 Name VARCHAR(100),
 Address VARCHAR(200),
 Age INT,
 PRIMARY KEY (Roll),
 UNIQUE(Email),
 CHECK(Age > 10)
);

CREATE TABLE Student(
 Roll char(4),
 Name VARCHAR(100),
 Address VARCHAR(200),
 Age INT,
 CONSTRAINT pk_rule PRIMARY KEY (Roll),
 CONSTRAINT un_rule UNIQUE(Email),
 CONSTRAINT check_rule CHECK(Age > 10)
);



CREATE TABLE Library(
	BookName VARCHAR(50),
    Who_Hired_Roll CHAR(4),
    FOREIGN KEY (Who_Hired_Roll) REFERENCES Student(Roll)
);

