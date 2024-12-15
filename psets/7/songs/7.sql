-- returns the average energy of songs that are by Drake

-- SELECT s.name, s.energy, a.name
SELECT avg(s.energy) as 'Average energy of songs written by Drake'
FROM songs s JOIN artists a ON s.artist_id = a.id
WHERE a.name = 'Drake';
