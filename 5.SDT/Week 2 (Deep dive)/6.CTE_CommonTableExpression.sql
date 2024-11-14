use dummydb;

with temp as
(
select *
from employees
limit 5
)

select *
from temp;

-- application of CTE
with AVGIT as
(
	select avg(salary) as sal1
	from employees
	where department_id = 60 -- IT
),
MAXMKT AS
(
	select max(salary) as sal2
	from employees
	where department_id = 20 -- Marketing
)

select * 
from employees
where salary > (select sal1 from avgit) and salary < (select sal2 from MAXMKT);