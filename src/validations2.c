#include "../includes/so_long.h"
#include <stdio.h>
#include <string.h>

int	check_border_rows(t_map *map)
{
	int	row;
	int	column;

	row = 0;
	while (map->array[row])
	{
		column = -1;
		while (map->array[row][++column])
		{
			if (!ft_strchr("1", map->array[row][column]))
				return (FALSE);
		}
		if (row++ == 0)
			row = map->array_size.y - 1;
	}
	return (TRUE);
}

int	check_middle_rows(t_map *map)
{
	int	row;
	int	column;

	row = 0;
	column = 0;
	while (++row < map->array_size.y - 1)
	{
		if (map->array[row][0] != '1'
			|| map->array[row][map->array_size.x - 1] != '1')
			return (FALSE);
	}
	return (TRUE);
}

int	check_surrounded(t_map *map)
{
	if (!check_border_rows(map))
		return (FALSE);
	else if (!check_middle_rows(map))
		return (FALSE);
	return (TRUE);
}

int	check_path(t_map *map)
{
	return (TRUE);
}

int	error_message(int error, int argc, char *argv[])
{
	if (error == WRONG_ARGUMENTS)
		perror("Error\n Wrong number of arguments (expected 2)");
	else if (error == WRONG_FILE_EXTENSION)
		perror("Error\nMap has invalid extension (expecting .ber)");
	else if (error == INVALID_CHARACTERS)
		perror("Error\nMap has invalid characters.");
	else if (error == MAP_NOT_RECTANGULAR)
		perror("Error\n The map must be rectangular.");
	else if (error == MAP_NOT_FOUND)
		perror("Error\nThe map was not found.");
	else if (error == MAP_NOT_SURROUNDED)
		perror("Error\nThe map must be surrounded by walls.");
	else if (error == NO_VALID_PATH)
		perror("Error\nTHe map has no valid path for winning.");
	return (FALSE);
}
