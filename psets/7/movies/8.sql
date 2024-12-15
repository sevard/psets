-- list the names of all people who starred in Toy Story.
--   Query should output a table with a single column for the name of each person.
--   You may assume that there is only one movie in the database with the title Toy Story.

-- Using subquery
-- SELECT id FROM movies WHERE title = 'Toy Story';
-- SELECT name FROM people
-- WHERE id IN
--     (SELECT person_id FROM stars WHERE movie_id IN
--         (SELECT id FROM movies WHERE title = 'Toy Story'));

-- Using JOIN
SELECT p.name
FROM people p
JOIN stars s ON p.id = s.person_id
JOIN movies m ON m.id = s.movie_id
WHERE m.title = 'Toy Story';


