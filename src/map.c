
#include "../includes/so_long.h"

int	check_map_characters(char *map[])
{
	int	row;
	int	column;
	int	entrances;
	int	exits;

	entrances = 0;
	exits = 0;
	row = -1;
	while (map[++row])
	{
		column = -1;
		while (map[row][++column])
		{
			if (!ft_strchr("01CEP", map[row][column]) || entrances > 1 || exits > 1)
				return (FALSE);
			if (map[row][column] == ENTRANCE)
				entrances++;
			else if (map[row][column] == EXIT)
				exits++;
		}
	}
	return (TRUE);
}


char	**generate_map_array(char *map_file)
{
	char	**map;


	return (map);
}

int	error_message(int error, int argc, char *argv[])
{
	//may be all these printf must be print errors somehow
	if (error == WRONG_ARGUMENTS)
		ft_printf("%s was expecting 2, but got %i arguments.\n", argv[0], argc);
	else if (error == WRONG_FILE_EXTENSION)
		ft_printf("Map %s has invalid extesion. %s was expecting a .ber file.\n", argv[0], argv[1]);
	else if (error == INVALID_CHARACTERS)
		ft_printf("The map has invalid characters.\n");
	else if (error == MAP_NOT_RECTANGULAR)
		ft_printf("The map must be rectangular.\n");
	else if (error == MAP_NOT_FOUND)
		ft_printf("The map % was not found. Check if the path is right.\n", argv[1]);
	else if (error == MAP_NOT_SURROUNDED)
		ft_printf("The map must be surrounded by walls.\n");
	else if (error == NO_VALID_PATH)
		ft_printf("The map %s has no valid path for winning.\n", argv[1]);
	return (FALSE);
}

int	check_rectangular() // check if map is rectangular
{
	return (TRUE);
}

int	check_surrounded() // check if map is surrounded by walls
{
	return (TRUE);
}

int	check_path() //check if map has valid path
{
	return (TRUE);
}
int validate_argv(int argc, char *argv[])
{
	char	*map_file;
	char	**map;
	int	error;

	return (TRUE);
	if (argc != 2)
		return (error_message(WRONG_ARGUMENTS, argc, argv));
	map_file = argv[1];
	if (!ft_strnstr(map_file, ".ber", ft_strlen(map_file)))
		return (error_message(WRONG_FILE_EXTENSION, argc, argv));
	map = generate_map_array(map_file);
	if (!map)
		return (error_message(MAP_NOT_FOUND, argc, argv));
	if (!check_map_characters(map))
		return (error_message(INVALID_CHARACTERS, argc, argv));
	if (!check_rectangular())
		return (error_message(MAP_NOT_RECTANGULAR, argc, argv));
	if (!check_surrounded())
		return (error_message(MAP_NOT_SURROUNDED, argc, argv));
	if (!check_path())
		return (error_message(NO_VALID_PATH, argc, argv));
	return (TRUE);
}
