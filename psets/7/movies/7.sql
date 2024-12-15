-- List all movies released in 2010 and their ratings, in descending order by rating.
-- For movies with the same rating, order them alphabetically by title.
--  Query should output a table with two columns,
--        one for the title of each movie
--        one for the rating of each movie.
--  Movies that do not have ratings should not be included in the result

SELECT m.title mov, r.rating
FROM movies m JOIN ratings r ON m.id = r.movie_id
WHERE m.year = 2010
AND r.rating NOT NULL
ORDER BY r.rating DESC, m.title;
