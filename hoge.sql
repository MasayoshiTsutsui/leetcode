SELECT c.name AS 国名, AVG(p.height) AS 平均身長
FROM country c 
JOIN players p ON p.country_id = c.id
GROUP BY c.id, c.name
ORDER BY AVG(p.height) DESC


SELECT (SELECT c.name FROM countries c WHERE ) AS 国名, AVG(p.height) AS 平均身長
FROM players p
ORDER BY AVG(p.height)


CREATE TABLE recipe( --レシピ作成者とレシピを紐づけるtable
    recipe_id int PRIMARY KEY
    user_id int,
);

CREATE TABLE photo_report( --フォトレポート投稿者とレシピとフォトレポートを紐付けるtable
    user_id int,
    recipe_id int,
    photo blob,
);



SELECT COUNT(recipe_id) FROM recipe
WHERE user_id NOT IN (SELECT recipe_id FROM photo_report)
