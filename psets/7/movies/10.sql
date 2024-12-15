-- list the names of all people who have directed a movie that received a rating of at least 9.0.
--     Output a table with a single column for the name of each person.
--     If a person directed more than one movie that received a rating of at least 9.0,
--          they should only appear in your results once.

-- TEST
-- SELECT COUNT(DISTINCT(name)) FROM people WHERE id
-- SELECT COUNT(name) FROM people WHERE id

-- Using subquery
SELECT DISTINCT(name) FROM people WHERE id
IN(SELECT person_id FROM directors WHERE movie_id
    IN(SELECT movie_id FROM ratings WHERE rating >= 9.0));

-- Using JOIN
-- SELECT COUNT(DISTINCT(name))
-- FROM people p
-- JOIN directors d ON p.id = d.person_id
-- JOIN ratings r ON r.movie_id = d.movie_id
-- WHERE r.rating >= 9.0 ;
