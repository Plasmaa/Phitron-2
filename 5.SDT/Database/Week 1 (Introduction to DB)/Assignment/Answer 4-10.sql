USE assignment_1;

CREATE TABLE Employee (
    EmployeeID INT PRIMARY KEY,
    FirstName VARCHAR(50),
    LastName VARCHAR(50),
    Age INT,
    Department VARCHAR(50)
);

INSERT INTO Employee (EmployeeID, FirstName, LastName, Age, Department) VALUES
(1, 'John', 'Doe', 28, 'Sales'),
(2, 'Jane', 'Smith', 32, 'Marketing'),
(3, 'Michael', 'Johnson', 35, 'Finance'),
(4, 'Sarah', 'Brown', 30, 'HR'),
(5, 'William', 'Davis', 25, 'Engineering'),
(6, 'Emily', 'Wilson', 28, 'Sales'),
(7, 'Robert', 'Lee', 33, 'Marketing'),
(8, 'Laura', 'Hall', 29, 'Finance'),
(9, 'Thomas', 'White', 31, 'HR'),
(10, 'Olivia', 'Clark', 27, 'Engineering');

SELECT DISTINCT Department 
FROM Employee;

SELECT LastName, Age 
FROM Employee
ORDER BY Age DESC;

SELECT LastName, Age 
FROM Employee
WHERE Age > 30 AND Department = 'Marketing';

SELECT * 
FROM Employee;

SELECT * 
FROM Employee
WHERE FirstName LIKE '%son%' OR LastName LIKE '%son%';

SELECT * 
FROM Employee
WHERE Department = 'Engineering';
