use dummydb;

-- Union 
select *
from employees
where salary > 10000
union
select *
from employees
where department_id = 100;

-- Intersetion
select *
from employees
where salary > 10000 
intersect
select *
from employees
where department_id = 100;

-- Minus
select *
from employees
where salary > 10000 and department_id != 100;



