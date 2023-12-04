#include "../includes/so_long.h"

int	get_map_size(char *map_file)
{
	int		fd;
	int		count;

	fd = open(map_file, O_RDONLY);
	count = 0;
	while (get_next_line(fd))
		count++;
	close(fd);
	return (count);
}

int	create_map(char *map_file, t_map *map)
{
	char	*buffer;
	int		fd;
	int		count;

	fd = open(map_file, O_RDONLY);
	buffer = get_next_line(fd);
	count = 0;
	map->array = (char **) malloc (sizeof(char *) * get_map_size(map_file) + 1);
	if (!map->array)
	{
		map->array = NULL;
		buffer = NULL;
	}
	while (buffer)
	{
		buffer[ft_strlen(buffer) - 1] = '\0';
		map->array[count++] = buffer;
		buffer = get_next_line(fd);
	}
	map->array[count] = NULL;
	return (fd);
}

t_map	generate_map(char *map_file)
{
	t_map	map;

	close(create_map(map_file, &map));
	set_collectibles_number(&map);
	return (map);
}

void	set_map_positions(t_map *map)
{
	int	column;
	int	row;

	row = 1;
	column = 1;
	while (map->array[row] && row < map->array_size.y)
	{
		column = 1;
		while (map->array[row][column])
		{
			if (map->array[row][column] == EXIT)
			{
				map->exit_position.y = row;
				map->exit_position.x = column;
			}
			else if (map->array[row][column] == ENTRANCE)
			{
				map->player_position.y = row;
				map->player_position.x = column;
			}
			column++;
		}
		row++;
	}
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
