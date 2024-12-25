use dummydb;

select *
from employees;

select first_name
from employees
where first_name = 'Steven';

-- subquery is a type of query which is inside another query

SELECT salary,first_name
FROM employees
WHERE salary < (SELECT salary
                FROM employees
                WHERE employee_id = 100);

select department_id
from departments
where department_name = 'marketing';

-- all info of those who works in marketing department
select *
from employees
where department_id = (select department_id
					   from departments
					   where department_name = 'marketing'
                       );
                       
-- all info of the person who gets the highest salary
select max(salary)
from employees;

select *
from employees
where salary = (select max(salary)
	   from employees
       );
       
-- How many person works in IT department ? 
select count(*) as IT_members
from employees
where department_id = (
						select department_id
                        from departments
                        where department_name = 'IT'
					  );

-- how much money is spent on programmers monthly ? 
select sum(salary) as Total_salary
from employees
where job_id = (select Job_id
				from jobs
                where job_title = "programmer");
                
                
-- ADVANCE SUB_QUERY
-- whats the second highest salary ? and who gets it ? 

select distinct salary
from employees
order by salary desc
limit 1
offset 1;

select * 
from employees
where salary = (select distinct salary
				from employees
				order by salary desc
				limit 1
				offset 1);
                
select *
from employees
where salary = (select max(salary)
				from employees
				where salary < (select max(salary)
								from employees
								)
				);
                
                
-- find who gets more salary than the manager 
select *
from employees as emp
where salary > (select salary
				from employees as mgr
                where emp.manager_id = mgr.employee_id
				);
                
-- which employees do the same job as the manager ?
select *
from employees as emp
where job_id = (select job_id
				from employees as mgr
                where emp.manager_id = mgr.employee_id
				);

 