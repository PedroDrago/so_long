/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:57:07 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/08 16:55:37 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

void	set_map(t_map *map)
{
	set_map_positions(map);
	generate_enemies(map, map->collectibles_number);
	map->array[map->array_size.y - 1][0] = ZERO;
	map->array[0][0] = ZERO;
}
