/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:24:45 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/08 16:54:37 by pdrago           ###   ########.fr       */
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

void	do_letters(t_map *map, t_character *player)
{
	char	*number;

	number = ft_itoa(player->movement_count);
	if ((int) ft_strlen(number) < map->array_size.x)
		set_movement_letters(map, number);
	free (number);
	number = ft_itoa(player->collectibles_count);
	if ((int) ft_strlen(number) < map->array_size.x)
		set_collectible_letters(map, number);
	free(number);
}
