-- select name
-- from t(Select COUNT(managerId) as num From Employee  ) 
-- where num >=5 ; 




SELECT name
FROM Employee
WHERE id IN (
    SELECT managerId
    FROM Employee
    WHERE managerId IS NOT NULL
    GROUP BY managerId
    -- HAVING COUNT(*) >= 5
    HAVING COUNT(managerId) >= 5
);
