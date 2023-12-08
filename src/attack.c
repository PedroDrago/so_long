/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 12:15:31 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/08 12:15:36 by pdrago           ###   ########.fr       */
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
	player->current = player->attacking;
	resolve_attack(player, map);
}
