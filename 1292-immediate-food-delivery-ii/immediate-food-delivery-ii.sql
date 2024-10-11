-- select (sum (if (order_date = customer_pref_delivery_date , 1, 0)) * 100 / count(delivery_id) )as immediate_percentage



select 
round(sum(case when d.order_date = d.customer_pref_delivery_date then 1 else 0 end)  * 100.0 / count(d.delivery_id) , 2 )as immediate_percentage
from Delivery d

Join 
(   select customer_id , Min(order_date) as first_order_date
    from Delivery
    group by customer_id
) as f 
on d.customer_id = f.customer_id AND d.order_date = f.first_order_date;
