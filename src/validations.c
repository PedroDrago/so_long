#include "../includes/so_long.h"

int	check_rectangular(t_map *map)
{
	int	row;
	int	column;
	int	row_size;

	row = -1;
	row_size = 0;
	while (map->array[++row])
	{
		column = -1;
		while (map->array[row][++column])
		{
			continue ;
		}
		if (row == 0)
			row_size = column;
		else if (column != row_size)
			return (FALSE);
	}
	if (row == column || row <= 2 || column <= 2)
		return (FALSE);
	map->array_size.x = column;
	map->array_size.y = row;
	return (TRUE);
}

int	validate_map(t_map *map)
{
	if (!map->array)
	{
		error_message(MAP_NOT_FOUND);
		exit(EXIT_FAILURE);
	}
	if (!check_map_characters(map->array))
		return (error_message(INVALID_CHARACTERS));
	if (!check_rectangular(map))
		return (error_message(MAP_NOT_RECTANGULAR));
	if (!check_surrounded(map))
		return (error_message(MAP_NOT_SURROUNDED));
	if (!check_path(map))
		return (error_message(NO_VALID_PATH));
	return (TRUE);
}

int	validate_argv(int argc, char *argv[])
{
	if (argc != 2)
		return (error_message(WRONG_ARGUMENTS));
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		return (error_message(WRONG_FILE_EXTENSION));
	return (TRUE);
}

int	check_map_characters(char *map[])
{
	struct s_validations	vars;

	vars.entrances = 0;
	vars.exits = 0;
	vars.row = -1;
	vars.collectibles = 0;
	while (map[++vars.row])
	{
		vars.column = -1;
		while (map[vars.row][++vars.column])
		{
			if (!ft_strchr("01CEP\n", map[vars.row][vars.column]))
				return (FALSE);
			if (map[vars.row][vars.column] == ENTRANCE)
				vars.entrances++;
			else if (map[vars.row][vars.column] == EXIT)
				vars.exits++;
			else if (map[vars.row][vars.column] == COLLECTIBLE)
				vars.collectibles++;
		}
	}
	if (vars.entrances != 1 || vars.exits != 1 || vars.collectibles < 1)
		return (FALSE);
	return (TRUE);
}
