# Write your MySQL query statement below


-- SELECT customer_id ,IF NULL (count_no_of_visit , 0 )
-- from Visits as a 
-- Left Join (SELECT COUNT(*) 
-- FROM  
-- )
-- on a.visit_id = b.visit_id 
-- where transaction_id = NULL AND count_no_of_visit = 

SELECT v.customer_id, COUNT(*) AS count_no_trans
FROM Visits v
LEFT JOIN Transactions t ON v.visit_id = t.visit_id
WHERE t.transaction_id IS NULL
GROUP BY v.customer_id;
