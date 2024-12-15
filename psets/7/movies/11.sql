-- List the titles of the five highest rated movies (in order) that Chadwick Boseman starred in,
-- starting with the highest rated.
    -- Query should output a table with a single column for the title of each movie.
    -- You may assume that there is only one person in the database with the name Chadwick Boseman.

-- Using mix of subquery and JOIN
-- SELECT m.title --, r.rating
-- FROM movies m JOIN ratings r ON m.id = r.movie_id
-- WHERE id
--         IN(SELECT movie_id FROM stars WHERE person_id =
--             (SELECT id FROM people WHERE name = 'Chadwick Boseman'))
-- ORDER BY r.rating DESC LIMIT 5;

-- Using JOIN
SELECT m.title
FROM movies m
    JOIN ratings r ON m.id = r.movie_id
    JOIN stars s ON m.id = s.movie_id
    JOIN people p ON p.id = s.person_id
WHERE p.name = 'Chadwick Boseman'
ORDER BY r.rating DESC LIMIT 5;

