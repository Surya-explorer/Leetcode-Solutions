select a.product_id , IFNULL(ROUND(SUM(a.price * b.units) / SUM(b.units) , 2 ) , 0) as average_price 
from Prices as a
LEFT  JOIN UnitsSold as b 
on a.product_id = b.product_id 
AND b.purchase_date >= a.start_date 
AND b.purchase_date <= a.end_date  
GROUP BY a.product_id ;