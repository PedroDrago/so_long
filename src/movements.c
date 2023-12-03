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
	if (key == W)
	{
		move_up(&game->map, &game->character);
	}
	else if (key == A)
	{
		move_left(&game->map, &game->character);
	}
	else if (key == S)
	{
		move_down(&game->map, &game->character);
	}
	else if (key == D)
	{
		move_right(&game->map, &game->character);
	}
	ft_printf("movement count: %u\n",
		game->character.movement_count += 1);
	ft_printf("Collectible count: %u/%u\n",
		game->character.collectibles_count, game->map.collectibles_number);
}
