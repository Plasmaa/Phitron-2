use dummydb;

select first_name, upper(first_name)
from employees;
select first_name, lower(first_name)
from employees;

select rand();
SELECT FLOOR(RAND() * 1000) AS RandomValue;
SELECT ROUND(RAND() * 1000) AS RandomValue;
SELECT RAND() * 1000 AS RandomValue;

select round(12.34531276,4);
select pi();
select cos(0);
select ACOS(1);
select cos(radians(90));
select radians(90);

-- group functions (max, min, avg, count, sum)
select max(salary) as Max_Salary, min(salary) as Min_Salary, avg(salary) as Average_Salary
from employees;
select count(salary)
from employees;
select count(employee_id) as Employee_count
from employees;
-- how many rows in the table
select count(*)
from employees;

-- group by having (a part of group functions)
select department_id,max(salary) 
from employees
group by department_id;

select department_id,max(salary) 
from employees
where department_id != 20
group by department_id
having max(salary) > 10000;

-- ALTER table query (for the structural change of a table)
-- for example - UPDATE & DELETE change the data of the table
-- ALTER & DROP change the structure or form of the table . example: adding new column, deleting a column
ALTER table employees
drop column salary;

select *
from employees;

ALTER table employees
modify column email varchar(500);



