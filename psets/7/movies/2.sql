-- Determine the birth year of Emma Stone.
    -- Query should output a table with a single column and a single row (not counting the header)
    --   containing Emma Stone’s birth year.
    -- You may assume that there is only one person in the database with the name Emma Stone.

SELECT birth FROM people
WHERE name = 'Emma Stone';
