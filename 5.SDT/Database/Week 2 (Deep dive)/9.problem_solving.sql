-- problem link -- https://leetcode.com/problems/duplicate-emails/

select email
from person
group by email
having count(email) > 1;

-- problem link -- https://leetcode.com/problems/employees-earning-more-than-their-managers/description/

select name as Employee
from employee as emp, employee as mgr
where emp.manager = mgr.id and emp.salary > mgr.salary;

-- problem link -- https://leetcode.com/problems/customers-who-never-order/
select customers.name as Customers
from customers
	left join orders 
		on customers.id = orders.customerid
group by customers.id 
having count(orders.id) = 0; 

