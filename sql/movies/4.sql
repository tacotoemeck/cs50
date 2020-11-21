SELECT COUNT(title) FROM movies
JOIN ratings on ratings.movie_id = movies.id
WHERE rating = 10;