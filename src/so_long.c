#include "../includes/so_long.h"
t_image	new_sprite(t_program *vars, char *path)
{
	t_image sprite;

	sprite.img = mlx_xpm_file_to_image(vars->mlx, path, &sprite.size.x, &sprite.size.y);
	sprite.addr = mlx_get_data_addr(sprite.img, &sprite.bits_per_pixel, &sprite.line_length, &sprite.endian);
	sprite.position.x = 0;
	sprite.position.y = 0;
	sprite.path = path;
	return (sprite);
}


void	change_to_up(t_character *character)
{
	character->current = character->up;
}

void	change_to_up_door(t_character *character)
{
	character->current = character->up_door;
}
void	change_to_down(t_character *character)
{
	character->current = character->down;
}

void	change_to_down_door(t_character *character)
{
	character->current = character->down_door;
}

void	change_to_left_door(t_character *character)
{
	character->current = character->left_door;
}

void	change_to_left(t_character *character)
{
	character->current = character->left;
}

void	change_to_right(t_character *character)
{
	character->current = character->right;
}

void	change_to_right_door(t_character *character)
{
	character->current = character->right_door;
}

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
		if (current_y == map->exit_position.y && current_x == map->exit_position.x)
			map->array[current_y][current_x] = EXIT;
		else
			map->array[current_y][current_x] = EMPTY;
		map->player_position.y--;
		if (current_y - 1 == map->exit_position.y && current_x == map->exit_position.x)
			change_to_up_door(player);
		else
			change_to_up(player);
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
		if (current_y == map->exit_position.y && current_x == map->exit_position.x)
			map->array[current_y][current_x] = EXIT;
		else
			map->array[current_y][current_x] = EMPTY;
		map->player_position.x--;
		if (current_y == map->exit_position.y && current_x + 1== map->exit_position.x)
			change_to_left_door(player);
		else
			change_to_left(player);
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
		if (current_y == map->exit_position.y && current_x == map->exit_position.x)
			map->array[current_y][current_x] = EXIT;
		else
			map->array[current_y][current_x] = EMPTY;
		map->player_position.y++;
		if (current_y + 1 == map->exit_position.y && current_x == map->exit_position.x)
			change_to_down_door(player);
		else
			change_to_down(player);
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
		if (current_y == map->exit_position.y && current_x == map->exit_position.x)
			map->array[current_y][current_x] = EXIT;
		else
			map->array[current_y][current_x] = EMPTY;
		map->player_position.x++;
		if (current_y == map->exit_position.y && current_x + 1== map->exit_position.x)
			change_to_right_door(player);
		else
			change_to_right(player);
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
	ft_printf("movement count: %u\n", game->character.movement_count += 1);
	ft_printf("Collectible count: %u/%u\n", game->character.collectibles_count, game->map.collectibles_number);
}

void	set_character(t_program *game)
{
	game->character.down = new_sprite(game, FROG_DOWN_PATH);
	game->character.down_door = new_sprite(game, FROG_DOWN_DOOR_PATH);
	game->character.up = new_sprite(game, FROG_UP_PATH);
	game->character.up_door = new_sprite(game, FROG_UP_DOOR_PATH);
	game->character.left = new_sprite(game, FROG_LEFT_PATH);
	game->character.left_door = new_sprite(game, FROG_LEFT_DOOR_PATH);
	game->character.right = new_sprite(game, FROG_RIGHT_PATH);
	game->character.right_door = new_sprite(game, FROG_RIGHT_DOOR_PATH);
	game->character.current = game->character.down;
	game->character.movement_count = 0;
	game->character.collectibles_count= 0;
	game->character.array_position.x = 0;
	game->character.array_position.y = 0;
}

void	set_sprites(t_program *game)
{
	game->exit.closed = new_sprite(game, EXIT_CLOSED_PATH);
	game->exit.open = new_sprite(game, EXIT_OPEN_PATH);
	game->exit.current = game->exit.closed;
	game->collectible = new_sprite(game, COLLECTIBLE_PATH);
	game->background = new_sprite(game, BACKGROUND_PATH);
	game->victory = new_sprite(game, VICTORY_PATH);
	game->wall = new_sprite(game, WALL_PATH);
	set_character(game);
}

void	render_tile(t_program *game, char object, t_coord pos)
{
	if (object == EMPTY)
		mlx_put_image_to_window(game->mlx, game->win, game->background.img, pos.x, pos.y);
	else if (object == WALL)
		mlx_put_image_to_window(game->mlx, game->win, game->wall.img, pos.x, pos.y);
	else if (object == COLLECTIBLE)
		mlx_put_image_to_window(game->mlx, game->win, game->collectible.img, pos.x, pos.y);
	else if (object == EXIT)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->exit.current.img, pos.x, pos.y);
		game->exit_position_pixel.x = pos.x;
		game->exit_position_pixel.y = pos.y;
	}
	else if (object == ENTRANCE || object == PLAYER)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->character.current.img, pos.x, pos.y);
		game->character.current.position.x = pos.x;
		game->character.current.position.y = pos.y;
	}
}

void	render_map(t_program *game)
{
	int	row;
	int	column;
	t_coord	pos;

	row = 0;
	pos.x = 0;
	pos.y = 0;
	while(game->map.array[row])
	{
		column = 0;
		pos.x = 0;
		while(game->map.array[row][column])
		{
			render_tile(game, game->map.array[row][column], pos);
			column++;
			pos.x += TILE_SIZE;
		}
		row++;
		pos.y += TILE_SIZE;

	}
}

void	exit_game(t_program *game)
{
	free(game->map.array);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_program	game;

	if (!validate_argv(argc, argv))
		exit(-1);
	game.map = generate_map(argv[1]);
	if (!validate_map(&game.map, argc, argv))
		exit_game(&game);
	set_map_positions(&game.map);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map.array_size.x * TILE_SIZE, game.map.array_size.y * TILE_SIZE, "So Long");
	mlx_key_hook(game.win, key_hook, &game);
	set_sprites(&game);
	mlx_loop(game.mlx);
}
