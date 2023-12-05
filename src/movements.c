/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:35:21 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/05 15:35:22 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_map *map, t_character *player)
{
	int	current_x;
	int	current_y;

	current_x = map->player_position.x;
	current_y = map->player_position.y;
	if (map->array[map->player_position.y - 1][map->player_position.x] != '1')
	{
		if (map->array[current_y - 1][current_x] == COLLECTIBLE)
			player->collectibles_count++;
		map->array[current_y - 1][current_x] = PLAYER;
		if (current_y == map->exit_position.y
			&& current_x == map->exit_position.x)
			map->array[current_y][current_x] = EXIT;
		else
			map->array[current_y][current_x] = EMPTY;
		map->player_position.y--;
		if (current_y - 1 == map->exit_position.y
			&& current_x == map->exit_position.x)
			player->current = player->up_door;
		else
			player->current = player->up;
	}
}

void	move_left(t_map *map, t_character *player)
{
	int	current_x;
	int	current_y;

	current_x = map->player_position.x;
	current_y = map->player_position.y;
	if (map->array[current_y][current_x - 1] != '1')
	{
		if (map->array[current_y][current_x - 1] == COLLECTIBLE)
			player->collectibles_count++;
		map->array[current_y][current_x - 1] = PLAYER;
		if (current_y == map->exit_position.y
			&& current_x == map->exit_position.x)
			map->array[current_y][current_x] = EXIT;
		else
			map->array[current_y][current_x] = EMPTY;
		map->player_position.x--;
		if (current_y == map->exit_position.y
			&& current_x - 1 == map->exit_position.x)
			player->current = player->left_door;
		else
			player->current = player->left;
	}
}

void	move_down(t_map *map, t_character *player)
{
	int	current_x;
	int	current_y;

	current_x = map->player_position.x;
	current_y = map->player_position.y;
	if (map->array[map->player_position.y + 1][map->player_position.x] != '1')
	{
		if (map->array[current_y + 1][current_x] == COLLECTIBLE)
			player->collectibles_count++;
		map->array[current_y + 1][current_x] = PLAYER;
		if (current_y == map->exit_position.y
			&& current_x == map->exit_position.x)
			map->array[current_y][current_x] = EXIT;
		else
			map->array[current_y][current_x] = EMPTY;
		map->player_position.y++;
		if (current_y + 1 == map->exit_position.y
			&& current_x == map->exit_position.x)
			player->current = player->down_door;
		else
			player->current = player->down;
	}
}

void	move_right(t_map *map, t_character *player)
{
	int	current_x;
	int	current_y;

	current_x = map->player_position.x;
	current_y = map->player_position.y;
	if (map->array[map->player_position.y][map->player_position.x + 1] != '1')
	{
		if (map->array[current_y][current_x + 1] == COLLECTIBLE)
			player->collectibles_count++;
		map->array[current_y][current_x + 1] = PLAYER;
		if (current_y == map->exit_position.y
			&& current_x == map->exit_position.x)
			map->array[current_y][current_x] = EXIT;
		else
			map->array[current_y][current_x] = EMPTY;
		map->player_position.x++;
		if (current_y == map->exit_position.y
			&& current_x + 1 == map->exit_position.x)
			player->current = player->right_door;
		else
			player->current = player->right;
	}
}

void	resolve_movement(int key, t_program *game)
{
	if (key == W || key == ARROW_UP)
		move_up(&game->map, &game->character);
	else if (key == A || key == ARROW_LEFT)
		move_left(&game->map, &game->character);
	else if (key == S || key == ARROW_DOWN)
		move_down(&game->map, &game->character);
	else if (key == D || key == ARROW_RIGHT)
		move_right(&game->map, &game->character);
}
