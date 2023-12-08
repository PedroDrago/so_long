/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:15:31 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/08 16:43:16 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	resolve_attack(t_character *player, t_map *map)
{
	if (map->array[map->player_position.y][map->player_position.x + 1] == ENEMY)
	{
		map->array[map->player_position.y][map->player_position.x + 1] = EMPTY;
		player->kill_count++;
	}
	if (map->array[map->player_position.y][map->player_position.x - 1] == ENEMY)
	{
		map->array[map->player_position.y][map->player_position.x - 1] = EMPTY;
		player->kill_count++;
	}
	if (map->array[map->player_position.y + 1][map->player_position.x] == ENEMY)
	{
		map->array[map->player_position.y + 1][map->player_position.x] = EMPTY;
		player->kill_count++;
	}
	if (map->array[map->player_position.y - 1][map->player_position.x] == ENEMY)
	{
		map->array[map->player_position.y - 1][map->player_position.x] = EMPTY;
		player->kill_count++;
	}
}

void	attack(t_character *player, t_map *map)
{
	if (map->player_position.x == map->exit_position.x
		&& map->player_position.y == map->exit_position.y)
		player->current = player->attacking_door;
	else
		player->current = player->attacking_grass;
	player->movement_count--;
	resolve_attack(player, map);
}
