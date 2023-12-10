/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:57:07 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/09 23:30:34 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
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
*/

void	set_map(t_map *map)
{
	int		column;
	int		str_index;
	char	*max_collect;

	column = 2;
	str_index = 0;
	max_collect = ft_itoa(map->collectibles_number);
	set_map_positions(map);
	generate_enemies(map, map->collectibles_number);
	map->array[map->array_size.y - 1][0] = ZERO;
	map->array[0][0] = ZERO;
	map->array[0][1] = SLASH;
	while (max_collect[str_index])
	{
		map->array[0][column] = choose_char(max_collect[str_index]);
		column++;
		str_index++;
	}
	free (max_collect);
}
