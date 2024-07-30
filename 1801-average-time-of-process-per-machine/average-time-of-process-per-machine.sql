Select a1.machine_id , ROUND ( AVG(a2.timestamp - a1.timestamp) , 3) 
AS processing_time 
from Activity as a1 
JOIN Activity as a2 
on a1.activity_type = 'start' AND a2.activity_type = 'end'
AND a1.machine_id = a2.machine_id 
AND a1.process_id = a2.process_id
GROUP BY a1.machine_id ;


-- -- a1.activity_type = 'end' AND a2.activity_type = 'start'
-- -- AVG(*) as processing_time
-- a1.timestamp < a2.timestamp
