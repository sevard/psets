-- Query to list the titles of all movies in which both Bradley Cooper and Jennifer Lawrence starred.
    -- Query should output a table with a single column for the title of each movie.
    -- You may assume that there is only one person in the database with the name Bradley Cooper.
    -- You may assume that there is only one person in the database with the name Jennifer Lawrence.

-- Find the ID of Bradley Cooper
-- Find the ID of Jennifer Lawrence
-- Find the IDs of movies associated with Bradley Cooper’s ID
-- Find the IDs of movies associated with Jennifer Lawrence’s ID
-- Find movie titles from the movie IDs associated with both Bradley Cooper and Jennifer Lawrence

-- results in a table with 1 column and 4 rows.
-- Using subquery
SELECT title FROM movies WHERE id
 IN(SELECT a.movie_id FROM stars a JOIN stars b ON a.movie_id = b.movie_id
     WHERE a.person_id = (SELECT id FROM people WHERE name = 'Bradley Cooper')
       AND b.person_id = (SELECT id FROM people WHERE name = 'Jennifer Lawrence'));
