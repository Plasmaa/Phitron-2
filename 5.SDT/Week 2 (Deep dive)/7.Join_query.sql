use dummydb;

-- Join table without join query (its complexity is n*m)

select * from departments;
select * from employees;

-- show first_name from employees table and department name from department table
select first_name, department_name
from employees, departments
where employees.employee_id = departments.department_id;

-- Join table with join query (it has better complexity)

select employees.first_name, departments.department_name
from employees
	join departments on employees.department_id = departments.department_id;
    
select employees.first_name, departments.department_name
from employees
	join departments using(department_id);

-- Inner join, right, left, cross join
select employees.first_name, departments.department_name
from employees
	inner join departments using(department_id); -- it is normal join

select employees.first_name, departments.department_name
from employees
	left join departments using(department_id);
    
select employees.first_name, departments.department_name
from employees
	right join departments using(department_id);

select employees.first_name, departments.department_name
from employees
	cross join departments using(department_id);
    
-- Self Join
-- Question 1. print first_name & manager name

select mgr.first_name as Employee_name, emp.first_name  as Manager_name
from employees as emp 
	join employees as mgr
	on emp.employee_id = mgr.manager_id;
    
-- Question 2. show the name of the department where there is no employee
select employees.employee_id,departments.department_name
from departments
	left join employees 
    on departments.department_id = employees.department_id
where employees.department_id is Null;

-- Question 3. show the name & salary of the employee who gets less than the average of that department salary
select employees.first_name, 
		employees.salary, 
        (select avg(salary) from employees where department_id = employees.department_id) - employees.salary
from employees
	join departments
		on employees.department_id = departments.department_id;
    
-- Question 4. show the name of the department where the minimum salary is more than 5000
select department_name, min(salary), avg(salary)
from employees
	join departments 
		on employees.department_id = departments.department_id
group by department_name
having min(salary) > 5000;

-- Question 5. Provide an example using the employees table to list employees who share the same manager ID, showing only their first names and manager IDs.
SELECT emp.first_name AS Employee_name, mgr.manager_id AS Manager_id
FROM employees AS emp
	JOIN employees AS mgr
		ON emp.manager_id = mgr.employee_id;

