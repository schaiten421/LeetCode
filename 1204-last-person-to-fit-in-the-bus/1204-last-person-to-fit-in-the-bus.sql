# Write your MySQL query statement below
SELECT person_name FROM (
SELECT *, SUM(weight) OVER (ORDER BY turn) AS cumm_sum FROM Queue) Enqueue
WHERE cumm_sum<=1000
ORDER BY turn DESC
LIMIT 1;