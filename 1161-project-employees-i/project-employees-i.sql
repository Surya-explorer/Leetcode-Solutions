select project_id , ROUND( SUM(b.experience_years)/COUNT(a.project_id), 2) as average_years

from Project as a 
LEFT JOIN Employee as b 
on a.employee_id = b.employee_id 

GROUP BY a.project_id ;