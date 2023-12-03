#include "../includes/so_long.h"
#include <fcntl.h>
#include <unistd.h>

int	get_map_size(char *map_file)
{
	int		fd;
	int		count;
	char	*buffer;

	fd = open(map_file, O_RDONLY);
	count = 0;
	while (get_next_line(fd))
		count++;
	close(fd);
	return (count);
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
