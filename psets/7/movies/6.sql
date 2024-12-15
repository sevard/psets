-- determine the average rating of all movies released in 2012
    -- query should output a table with a single column and a single row (not counting the header) containing the average rating.

SELECT avg(rating) FROM movies m
JOIN ratings r ON m.id = r.movie_id
WHERE m.year = 2012;

