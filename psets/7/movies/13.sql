-- query to list the names of all people who starred in a movie in which Kevin Bacon also starred.

--     Your query should output a table with a single column for the name of each person.
--     There may be multiple people named Kevin Bacon in the database. Be sure to only select the Kevin Bacon born in 1958.
--     Kevin Bacon himself should not be included in the resulting list.

-- results in a table with 1 column and 182 rows.
SELECT name FROM people WHERE id
    IN(SELECT person_id FROM stars WHERE movie_id
      IN(SELECT movie_id FROM stars WHERE person_id
        =(SELECT id FROM people WHERE name = 'Kevin Bacon')))
AND name != 'Kevin Bacon';
