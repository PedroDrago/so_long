/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:14:10 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/08 16:56:29 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_with_enemies(t_map *map, int row, int column)
{
	if (map->array[row + 1][column] == EMPTY)
		map->array[row + 1][column] = ENEMY;
	else if (map->array[row - 1][column] == EMPTY)
		map->array[row - 1][column] = ENEMY;
	else if (map->array[row][column + 1] == EMPTY)
		map->array[row][column + 1] = ENEMY;
	else if (map->array[row][column - 1] == EMPTY)
		map->array[row][column - 1] = ENEMY;
}

void	generate_enemies(t_map *map, int enemies_number)
{
	int	column;
	int	row;
	int	enemies;

	row = 1;
	column = 1;
	enemies = 0;
	while (map->array[row] && row < map->array_size.y
		&& enemies <= enemies_number)
	{
		column = 1;
		while (map->array[row][column])
		{
			if (map->array[row][column] == COLLECTIBLE
				&& (column % 2 == 0 || row % 2 == 0))
			{
				fill_with_enemies(map, row, column);
				enemies++;
			}
			column++;
		}
		row++;
	}
}
