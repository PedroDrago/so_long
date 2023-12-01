
#include "../includes/so_long.h"
#include <fcntl.h>
#include <unistd.h>

int validate_map(t_map *map, int argc, char *argv[])
{
	if (!map->array)
		return (error_message(MAP_NOT_FOUND, argc, argv)); 
	if (!check_map_characters(map->array))
		return (error_message(INVALID_CHARACTERS, argc, argv));
	if (!check_rectangular(map))
		return (error_message(MAP_NOT_RECTANGULAR, argc, argv));
	if (!check_surrounded(map))
		return (error_message(MAP_NOT_SURROUNDED, argc, argv));
	// if (!check_path())
	// 	return (error_message(NO_VALID_PATH, argc, argv));
	return (TRUE);
}

int validate_argv(int argc, char *argv[])
{
	int	error;

	if (argc != 2)
		return (error_message(WRONG_ARGUMENTS, argc, argv));
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		return (error_message(WRONG_FILE_EXTENSION, argc, argv));
	return (TRUE);
}

int	check_map_characters(char *map[])
{
	int	row;
	int	column;
	int	entrances;
	int	exits;
	int	collectibles;

	entrances = 0;
	exits = 0;
	row = -1;
	collectibles = 0;
	while (map[++row])
	{
		column = -1;
		while (map[row][++column])
		{
			if (!ft_strchr("01CEP\n", map[row][column]))
				return (FALSE);
			if (map[row][column] == ENTRANCE)
				entrances++;
			else if (map[row][column] == EXIT)
				exits++;
			else if  (map[row][column] == COLLECTIBLE)
				collectibles++;
		}
	}
	if (entrances != 1 || exits != 1 || collectibles < 1)
		return (FALSE);
	return (TRUE);
}

int	get_map_size(char *map_file)
{	
	int	fd;
	int	count;
	char	*buffer;

	fd = open(map_file, O_RDONLY);
	count = 0;
	while (get_next_line(fd))
	{	
		count++;
	}
	close(fd);
	return (count);
}

t_map	generate_map(char *map_file)
{
	t_map	map;
	char	*buffer;
	char	**array;
	int	fd;
	int	count;

	fd = open(map_file, O_RDONLY);
	buffer = get_next_line(fd);
	count = 0;
	array = (char **) malloc (sizeof(char *) * get_map_size(map_file) + 1);
	if (!array)
	{
		array = NULL;
		buffer = NULL;
	}
	while (buffer)
	{	
		buffer[ft_strlen(buffer) - 1] = '\0';
		array[count++] = buffer;
		buffer = get_next_line(fd);
	}
	array[count] = NULL;
	map.array = array;
	set_collectibles_number(&map);
	close(fd);
	return (map);
}

int	error_message(int error, int argc, char *argv[])
{
	//may be all these printf must be print errors somehow
	if (error == WRONG_ARGUMENTS)
		ft_printf("Error\n%s was expecting 2, but got %i arguments.\n", argv[0], argc);
	else if (error == WRONG_FILE_EXTENSION)
		ft_printf("Error\nMap %s has invalid extesion. %s was expecting a .ber file.\n", argv[1], argv[0] + 2);
	else if (error == INVALID_CHARACTERS)
		ft_printf("Error\nThe map has invalid characters.\n");
	else if (error == MAP_NOT_RECTANGULAR)
		ft_printf("Error\nThe map must be rectangular.\n");
	else if (error == MAP_NOT_FOUND)
		ft_printf("Error\nThe map % was not found. Check if the path is right.\n", argv[1]);
	else if (error == MAP_NOT_SURROUNDED)
		ft_printf("Error\nThe map must be surrounded by walls.\n");
	else if (error == NO_VALID_PATH)
		ft_printf("Error\nThe map %s has no valid path for winning.\n", argv[1]);
	return (FALSE);
}

void	set_collectibles_number(t_map *map)
{
	int	row;
	int	column;

	row = -1;
	map->collectibles_number = 0;
	while (map->array[++row])
	{
		column = -1;
		while (map->array[row][++column])
		{
			if (map->array[row][column] == COLLECTIBLE)
				map->collectibles_number++;
		}
	}
}

int	check_rectangular(t_map *map)
{
	int	row;
	int	column;
	int	row_size;

	row = -1;
	row_size = 0;
	while(map->array[++row])
	{
		column = -1;
		while(map->array[row][++column])
		{
			;
		}
		if (row == 0)
			row_size = column;
		else if (column != row_size)
			return (FALSE);
	}
	if (row == column || row <= 2|| column <= 2)
		return (FALSE);
	map->array_size.x = column;
	map->array_size.y = row;
	return (TRUE);
}

int	check_border_rows(t_map *map)
{
	int	row;
	int	column;

	row = 0;
	while (map->array[row])
	{
		column = -1;
		while(map->array[row][++column])
		{
			if (!ft_strchr("1", map->array[row][column]))
				return (FALSE);
		}
		if (row++ == 0)
			row = map->array_size.y - 1; // -1 may be wrong
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
		if (map->array[row][0] != '1' || map->array[row][map->array_size.x - 1] != '1')
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

void	print_map_status(t_map *map)
{
	int	row;
	int	column;

	row = -1;
	while (map->array[++row])
	{
		column = -1;
		while (map->array[row][++column])
		{
			ft_printf("%c", map->array[row][column]);
		}
		ft_printf("\n");
	}
	ft_printf("Array x: %i\n", map->array_size.x);
	ft_printf("Array y: %i\n", map->array_size.y);
	ft_printf("Collectibles: %i\n", map->collectibles_number);
}

