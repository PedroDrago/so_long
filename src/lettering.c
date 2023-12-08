#include "../includes/so_long.h"

int	choose_char(char c)
{
	if (c == '0')
		return (ZERO);
	else if (c == '1')
		return (ONE);
	return (c);
}

void	set_movement_letters(t_map *map, char *number)
{
	int	column;
	int	count;

	count = 0;
	//have to check if number length isnt greater than every row length;
	column = map->array_size.y - 1;
	while(map->array[column][count] && number[count])
	{
		map->array[column][count] = choose_char(number[count]);
		count++;
	}
}

void	set_collectible_letters(t_map *map, char *number)
{
	int	column;
	int	count;

	count = 0;
	//have to check if number length isnt greater than every row length;
	column = 0;
	while(map->array[column][count] && number[count])
	{
		map->array[column][count] = choose_char(number[count]);
		count++;
	}
}
