SELECT  query_name ,
round (AVG(rating / position) , 2) as quality , 
round ( AVG(if (rating < 3 , 1, 0 ) * 100 ) , 2) as poor_query_percentage 
FROM Queries
WHERE 
query_name IS NOT NULL
group by  query_name  ;
