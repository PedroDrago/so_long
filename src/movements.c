/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:54:24 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/09 21:36:43 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_map *map, t_character *player)
{
	int	current_x;
	int	current_y;

	current_x = map->player_position.x;
	current_y = map->player_position.y;
	if (map->array[map->player_position.y - 1][map->player_position.x] != WALL)
	{
		if (map->array[current_y - 1][current_x] == COLLECTIBLE)
			player->collectibles_count++;
		else if (map->array[current_y - 1][current_x] == ENEMY)
			player->dead = TRUE;
		map->array[current_y - 1][current_x] = PLAYER;
		if (is_exit(map, current_x, current_y))
			map->array[current_y][current_x] = EXIT;
		else
			map->array[current_y][current_x] = EMPTY;
		map->player_position.y--;
		if (is_exit(map, current_x, current_y - 1))
			player->current = player->up_door;
		else
			player->current = player->up;
		do_letters(map, player);
	}
}

void	move_left(t_map *map, t_character *player)
{
	int	current_x;
	int	current_y;

	current_x = map->player_position.x;
	current_y = map->player_position.y;
	if (map->array[current_y][current_x - 1] != WALL)
	{
		if (map->array[current_y][current_x - 1] == COLLECTIBLE)
			player->collectibles_count++;
		else if (map->array[current_y][current_x - 1] == ENEMY)
			player->dead = TRUE;
		map->array[current_y][current_x - 1] = PLAYER;
		if (is_exit(map, current_x, current_y))
			map->array[current_y][current_x] = EXIT;
		else
			map->array[current_y][current_x] = EMPTY;
		map->player_position.x--;
		if (is_exit(map, current_x - 1, current_y))
			player->current = player->left_door;
		else
			player->current = player->left;
		do_letters(map, player);
	}
}

void	move_down(t_map *map, t_character *player)
{
	int	current_x;
	int	current_y;

	current_x = map->player_position.x;
	current_y = map->player_position.y;
	if (map->array[map->player_position.y + 1][map->player_position.x] != WALL)
	{
		if (map->array[current_y + 1][current_x] == COLLECTIBLE)
			player->collectibles_count++;
		else if (map->array[current_y + 1][current_x] == ENEMY)
			player->dead = TRUE;
		map->array[current_y + 1][current_x] = PLAYER;
		if (is_exit(map, current_x, current_y))
			map->array[current_y][current_x] = EXIT;
		else
			map->array[current_y][current_x] = EMPTY;
		map->player_position.y++;
		if (is_exit(map, current_x, current_y + 1))
			player->current = player->down_door;
		else
			player->current = player->down;
		do_letters(map, player);
	}
}

void	move_right(t_map *map, t_character *player)
{
	int	current_x;
	int	current_y;

	current_x = map->player_position.x;
	current_y = map->player_position.y;
	if (map->array[map->player_position.y][map->player_position.x + 1] != WALL)
	{
		if (is_collectible(map, current_x + 1, current_y))
			player->collectibles_count++;
		else if (is_enemy(map, current_x + 1, current_y))
			player->dead = TRUE;
		map->array[current_y][current_x + 1] = PLAYER;
		if (is_exit(map, current_x, current_y))
			map->array[current_y][current_x] = EXIT;
		else
			map->array[current_y][current_x] = EMPTY;
		map->player_position.x++;
		if (is_exit(map, current_x + 1, current_y))
			player->current = player->right_door;
		else
			player->current = player->right;
		do_letters(map, player);
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
