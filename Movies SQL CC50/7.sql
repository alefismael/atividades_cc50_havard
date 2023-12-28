SELECT rating, title
FROM ratings
INNER JOIN movies ON ratings.movie_id = movies.id
WHERE movies.year = 2010
ORDER BY rating DESC, title;