# Write your MySQL query statement below


SELECT b.product_name , a.year , a.price
FROM Sales as a
Left Join Product as b
on a.product_id = b.product_id ;