/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:57:07 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/09 23:25:45 by pdrago           ###   ########.fr       */
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
	int	count;
	int	count2;
	char	*max_collect;

	count = 2;
	count2 = 0;
	max_collect = ft_itoa(map->collectibles_number);
	set_map_positions(map);
	generate_enemies(map, map->collectibles_number);
	map->array[map->array_size.y - 1][0] = ZERO;
	map->array[0][0] = ZERO;
	map->array[0][1] = SLASH;
	while (max_collect[count2])
	{
		map->array[0][count] = choose_char(max_collect[count2]);
		count++;
		count2++;
	}
	free (max_collect);
}
