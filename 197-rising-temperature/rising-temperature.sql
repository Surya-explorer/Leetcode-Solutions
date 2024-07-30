SELECT w1.id 
from Weather as w1
JOIN Weather as w2 ON w1.recordDate = 
DATE_ADD(w2.recordDate, INTERVAL 1 DAY)
WHERE w1.temperature > w2.temperature
ORDER BY w1.recordDate ;