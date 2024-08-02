-- -- select b.contest_id , ROUND((COUNT(b.user_id)/COUNT(a.user_id)) *100 , 2 ) as percentage 
-- select b.contest_id , ROUND( (COUNT(b.user_id)/(SELECT COUNT(*) FROM Users)) *100 , 2 )as percentage 
-- from Users as a 
-- LEFT JOIN Register as b 
-- on a.user_id  = b.user_id 
-- GROUP by b.contest_id
-- ORDER BY percentage DESC  , contest_id ASC ;

SELECT 
    r.contest_id,
    ROUND(COUNT(r.user_id) * 100.0 / (SELECT COUNT(*) FROM Users), 2) AS percentage
FROM 
    Register r
GROUP BY 
    r.contest_id
ORDER BY 
    percentage DESC,
    contest_id ASC;
