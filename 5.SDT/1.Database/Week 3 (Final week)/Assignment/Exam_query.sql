create database final_exam;

use final_exam;

CREATE TABLE Instructor (	
    InstructorID INT AUTO_INCREMENT PRIMARY KEY,	
    Name VARCHAR(255) NOT NULL,	
    Email VARCHAR(255) NOT NULL UNIQUE,	
    Phone VARCHAR(15),	
    Department VARCHAR(50)	
);	

CREATE TABLE Student (	
    StudentID INT AUTO_INCREMENT PRIMARY KEY,	
    Name VARCHAR(255) NOT NULL,	
    Email VARCHAR(255) NOT NULL UNIQUE,	
    Phone VARCHAR(15)	
);

CREATE TABLE Course (	
    CourseID INT AUTO_INCREMENT PRIMARY KEY,	
    Title VARCHAR(255) NOT NULL,	
    Credits INT NOT NULL,	
    InstructorID INT,	
    FOREIGN KEY (InstructorID) REFERENCES Instructor(InstructorID)	
);	

CREATE TABLE Enrollment (	
    EnrollmentID INT AUTO_INCREMENT PRIMARY KEY,	
    StudentID INT,	
    CourseID INT,	
    EnrollmentDate DATE NOT NULL,	
    FOREIGN KEY (StudentID) REFERENCES Student(StudentID),	
    FOREIGN KEY (CourseID) REFERENCES Course(CourseID)	
);	

INSERT INTO Instructor (Name, Email, Phone, Department)
VALUES
('Alice Johnson', 'alice.johnson@example.com', '555-101-2020', 'Computer Science'),
('Bob Smith', 'bob.smith@example.com', '555-202-3030', 'Mathematics'),
('Carol Davis', 'carol.davis@example.com', '555-303-4040', 'Physics');

INSERT INTO Course (Title, Credits, InstructorID)
VALUES
('Introduction to SQL', 3, 1),
('Data Structures', 4, 2),
('Machine Learning', 5, 1),
('Discrete Mathematics', 3, 2),
('Quantum Physics', 5, 3);

INSERT INTO Student (Name, Email, Phone)
VALUES
('John Doe', 'john.doe@example.com', '123-456-7890'),
('Jane Smith', 'jane.smith@example.com', '234-567-8901'),
('Samuel Brown', 'samuel.brown@example.com', '345-678-9012'),
('Emily White', 'emily.white@example.com', '456-789-0123'),
('Michael Green', 'michael.green@example.com', '567-890-1234');

INSERT INTO Enrollment (StudentID, CourseID, EnrollmentDate)
VALUES
(1, 1, '2024-11-01'),
(2, 2, '2024-11-02'),
(3, 3, '2024-11-03'),
(4, 4, '2024-11-04'),
(5, 5, '2024-11-05');


-- question-> 2
INSERT INTO Enrollment (StudentID, CourseID, EnrollmentDate)
SELECT 5, CourseID, '2024-11-20'
FROM Course
ORDER BY Credits DESC
LIMIT 1;

-- question-> 3
UPDATE Course
SET InstructorID = 2
WHERE CourseID = 3;

-- question -> 4
SELECT Instructor.Name, SUM(Course.Credits) AS TotalCredits
FROM Instructor
JOIN Course ON Instructor.InstructorID = Course.InstructorID
GROUP BY Instructor.InstructorID, Instructor.Name
HAVING SUM(Course.Credits) = (
    SELECT MAX(TotalCredits)
    FROM (
        SELECT SUM(Course.Credits) AS TotalCredits
        FROM Course
        GROUP BY Course.InstructorID
    ) AS CreditTotals
);

-- question -> 5
SELECT Student.Name
FROM Student
JOIN Enrollment ON Student.StudentID = Enrollment.StudentID
GROUP BY Student.StudentID, Student.Name
HAVING COUNT(Enrollment.CourseID) > 2;

-- question -> 8
SELECT Salary
FROM Instructor
ORDER BY Salary DESC
LIMIT 1 OFFSET 1;




SELECT * FROM Instructor;
SELECT * FROM Course;
SELECT * FROM Enrollment;









