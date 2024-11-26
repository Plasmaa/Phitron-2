use dummydb;

select *
from countries;

select employee_id
from employees;

select department_id,last_name,salary
from employees
where department_id = 60 and salary > 1000;

-- show salary of who's salary is greater than bruce
select first_name,job_id,salary
from employees
where salary > 6000;

-- show disticnt job_id
select distinct job_id,first_name
from employees;

-- order by
select first_name,job_id,salary
from employees
order by salary;

select first_name,job_id,salary
from employees
order by salary desc;

-- limit 
select first_name,job_id,salary
from employees
order by salary desc
limit 4,5;

-- limit & offset
-- offset = how many to exclude && limit = how many to see after excluding with offset
select first_name,job_id,salary
from employees
order by salary desc
limit 5
offset 4;

-- like & AS
select last_name,job_id,salary
from employees
where last_name like "%green%";

select first_name, salary , salary+500 AS Bonus_salary
from employees;
