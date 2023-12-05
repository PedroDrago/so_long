/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:35:16 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/05 15:35:17 by pdrago           ###   ########.fr       */
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
