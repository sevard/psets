-- list the titles of all movies with a release date on or after 2018, in alphabetical order.
    -- query should output a table with a single column for the title of each movie.
    -- Movies released in 2018 should be included, as should movies with release dates in the future.

-- Should result in a table with 1 column and 110,014 rows.
SELECT title FROM movies
WHERE year >= '2018'
ORDER BY title;
