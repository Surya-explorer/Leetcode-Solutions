select a.student_id , a.student_name , b.subject_name , count(c.student_id) as attended_exams 
from Students as a 
cross join Subjects as b 
left join Examinations as c
on a.student_id = c.student_id and b.subject_name = c.subject_name

GROUP BY a.student_id , a.student_name , b.subject_name 
ORDER BY a.student_id, b.subject_name;