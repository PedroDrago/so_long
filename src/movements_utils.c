/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:24:45 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/09 21:45:52 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_collectible(t_map *map, int x, int y)
{
	return (map->array[y][x] == COLLECTIBLE);
}

int	is_enemy(t_map *map, int x, int y)
{
	return (map->array[y][x] == ENEMY);
}

int	is_exit(t_map *map, int x, int y)
{
	return (x == map->exit_position.x && y == map->exit_position.y);
}
