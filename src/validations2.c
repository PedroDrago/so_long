#include "../includes/so_long.h"

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

	row = 0;
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
	(void) map;
	return (TRUE);
}

int	error_message(int error)
{
	if (error == WRONG_ARGUMENTS)
		perror("\e[31mError\nWrong number of arguments (expected 2)\e[0m");
	else if (error == WRONG_FILE_EXTENSION)
		perror("\e[31mError\nMap has invalid extension (expecting .ber)\e[0m");
	else if (error == INVALID_CHARACTERS)
		perror("\e[31mError\nMap has invalid characters.\e[0m");
	else if (error == MAP_NOT_RECTANGULAR)
		perror("\e[31mError\n The map must be rectangular.\e[0m");
	else if (error == MAP_NOT_FOUND)
		perror("\e[31mError\nThe map was not found.\e[0m");
	else if (error == MAP_NOT_SURROUNDED)
		perror("\e[31mError\nThe map must be surrounded by walls.\e[0m");
	else if (error == NO_VALID_PATH)
		perror("\e[31mError\nTHe map has no valid path for winning.\e[0m");
	return (FALSE);
}
