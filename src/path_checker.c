/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:34:40 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/05 15:34:41 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	path_checker(char *map[], int x, int y)
{
	if (map[x][y] == WALL)
		return ;
	map[x][y] = WALL;
	path_checker(map, x - 1, y);
	path_checker(map, x + 1, y);
	path_checker(map, x, y - 1);
	path_checker(map, x, y + 1);
}

int	check_path(char *map_file)
{
	int		row;
	int		column;
	t_map	copy;

	copy = generate_map(map_file);
	check_rectangular(&copy);
	set_map_positions(&copy);
	row = -1;
	path_checker(copy.array, copy.player_position.x, copy.player_position.y);
	while (copy.array[++row])
	{
		column = -1;
		while (copy.array[++column])
		{
			if (copy.array[row][column] == EXIT
				|| copy.array[row][column] == COLLECTIBLE)
			{
				destroy_map(&copy);
				return (FALSE);
			}
		}
	}
	destroy_map(&copy);
	return (TRUE);
}
