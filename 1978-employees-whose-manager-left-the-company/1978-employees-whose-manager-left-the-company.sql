select employee_id from employees where salary < 30000 and
manager_id not in (select e.employee_id from employees e) order by employee_id;