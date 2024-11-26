-- Create Employees Table
create database Mid_term;
use Mid_term;
CREATE TABLE Employees (
    Employee_Id INT PRIMARY KEY,
    First_Name VARCHAR(50) NOT NULL,
    Last_Name VARCHAR(50),
    Date_of_Birth DATE,
    Department_Id INT,
    Salary DECIMAL(10, 2)
);

-- Create Projects Table
CREATE TABLE Projects (
    Project_ID INT PRIMARY KEY,
    Project_Name VARCHAR(100) NOT NULL,
    Start_Date DATE,
    End_Date DATE,
    Budget INT
);

-- Create Employee_Projects Table for Many-to-Many Relationship
CREATE TABLE Employee_Projects (
    Employee_Id INT,
    Project_ID INT,
    FOREIGN KEY (Employee_Id) REFERENCES Employees(Employee_Id),
    FOREIGN KEY (Project_ID) REFERENCES Projects(Project_ID),
    PRIMARY KEY (Employee_Id, Project_ID)
);

-- Ans Number of 4
use dummydb;
select distinct salary
from employees
order by salary desc
limit 1
offset 2;

SELECT d.Department_Name, COUNT(e.Employee_Id) AS Number_of_Employees
FROM Departments AS d
	JOIN Employees AS e 
		ON d.Department_Id = e.Department_Id
GROUP BY d.Department_Name;

USE dummydb;
-- Answer 7
-- Define the CTE to calculate the average salary
WITH AvgSalary AS (
    SELECT AVG(salary) AS avg_sal
    FROM employees
)
-- Use the CTE to select employees with salary higher than the average
SELECT first_name, last_name, salary
FROM employees
WHERE salary > (SELECT avg_sal FROM AvgSalary);


-- Answer = 8
SELECT first_name, last_name, salary
FROM employees
WHERE salary < (
    SELECT salary
    FROM employees
    WHERE first_name = 'Steven' AND last_name = 'King'
);


-- Answer = 9
SELECT d.department_name, e.first_name AS manager_name
FROM departments AS d
	JOIN employees AS e 
		ON d.manager_id = e.employee_id;

-- Answer = 10
select *
from departments;
SELECT DISTINCT l.city
FROM departments AS d
	JOIN locations AS l 
		ON d.location_id = l.location_id;





