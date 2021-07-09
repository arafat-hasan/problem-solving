# Write your MySQL query statement below
SELECT id,
SUM(CASE month WHEN 'Jan' THEN revenue ELSE Null END) AS Jan_Revenue,
SUM(CASE month WHEN 'Feb' THEN revenue ELSE Null END) AS Feb_Revenue,
SUM(CASE month WHEN 'Mar' THEN revenue ELSE Null END) AS Mar_Revenue,
SUM(CASE month WHEN 'Apr' THEN revenue ELSE Null END) AS Apr_Revenue,
SUM(CASE month WHEN 'May' THEN revenue ELSE Null END) AS May_Revenue,
SUM(CASE month WHEN 'Jun' THEN revenue ELSE Null END) AS Jun_Revenue,
SUM(CASE month WHEN 'Jul' THEN revenue ELSE Null END) AS Jul_Revenue,
SUM(CASE month WHEN 'Aug' THEN revenue ELSE Null END) AS Aug_Revenue,
SUM(CASE month WHEN 'Sep' THEN revenue ELSE Null END) AS Sep_Revenue,
SUM(CASE month WHEN 'Oct' THEN revenue ELSE Null END) AS Oct_Revenue,
SUM(CASE month WHEN 'Nov' THEN revenue ELSE Null END) AS Nov_Revenue,
SUM(CASE month WHEN 'Dec' THEN revenue ELSE Null END) AS Dec_Revenue
FROM Department
GROUP BY id
