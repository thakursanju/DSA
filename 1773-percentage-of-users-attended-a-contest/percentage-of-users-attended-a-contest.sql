SELECT 
    r.contest_id,
    ROUND(
        COUNT(DISTINCT r.user_id) * 100 /
        (SELECT COUNT(user_id) FROM Users),
        2
    ) AS percentage
FROM Users u
LEFT JOIN Register r
    ON u.user_id = r.user_id
WHERE r.contest_id IS NOT NULL
GROUP BY r.contest_id
ORDER BY percentage desc,r.contest_id ASC;