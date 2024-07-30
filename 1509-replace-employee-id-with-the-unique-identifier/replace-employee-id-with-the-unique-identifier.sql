# Write your MySQL query statement below

select a.name , b.unique_id
from Employees as a 
LEFT JOIN EmployeeUNI as b
on a.id = b.id 

-- SELECT e.name, eu.unique_id
-- FROM Employees e
-- LEFT JOIN EmployeeUNI eu 
-- ON e.id = eu.id;
