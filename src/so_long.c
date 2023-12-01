#include "../includes/so_long.h"

t_image	new_sprite(t_program *vars, char *path)
{
	t_image sprite;

	sprite.img = mlx_xpm_file_to_image(vars->mlx, path, &sprite.size.x, &sprite.size.y);
	sprite.addr = mlx_get_data_addr(sprite.img, &sprite.bits_per_pixel, &sprite.line_length, &sprite.endian);
	sprite.position.x = 0;
	sprite.position.y = 0;
	sprite.path = path;
	sprite.border.up = sprite.position.y - sprite.size.y / 2;
	sprite.border.down = sprite.position.y + sprite.size.y / 2;
	sprite.border.right = sprite.position.x + sprite.size.x / 2;
	sprite.border.left = sprite.position.x - sprite.size.x / 2;
	//think better about this border system, idk if its necessary, but maybe will help
	//when uptading position border should always update too
	//Better make function update_position(t_program *game) and update_border(t_program *game);
	//This border calculation is suposed to point to the outter most pixel of each side, indicating when character would be out of bound with precision
	//but if we're going to make a tile game, this wont be necessary
	return (sprite);
}

t_image copy_sprite(t_program *game, t_image old)
{
	t_image new;

	new = new_sprite(game, old.path);
	new.position.x = old.position.x;
	new.position.y = old.position.y;
	return (new);
}

void	render_frame(t_program *game)
{
	// update_positions(); -> this function will set all character images to the same position as current
	mlx_put_image_to_window(game->mlx, game->win, game->background.img, game->background.position.x, game->background.position.y);
	mlx_put_image_to_window(game->mlx, game->win, game->character.current.img, game->character.current.position.x, game->character.current.position.y);
}

void	change_to_attack(t_character *character)
{
	character->attacking.position = character->current.position;
	character->current = character->attacking;
}

void	change_to_idle(t_character *character)
{
	character->idle.position = character->current.position;
	character->current = character->idle;
}
void	resolve_movement(int key, t_program *game)
{
	int pos_x;
	int pos_y;
	int size_x;
	int size_y;

	pos_x = game->character.current.position.x;
	pos_y = game->character.current.position.y;
	size_x = game->character.current.size.x;
	size_y = game->character.current.size.y;
	change_to_idle(&game->character);
	if (key == W)
	{
		if (pos_y - size_y >= 0)
			game->character.current.position.y -= game->character.current.size.y;
	}
	else if (key == A)
	{
		if (pos_x - size_x >= 0)
			game->character.current.position.x -= game->character.current.size.x;
	}
	else if (key == S)
	{
		if (pos_y + size_y <= game->background.size.y)
			game->character.current.position.y += game->character.current.size.y;
	}
	else if (key == D)
	{
		if (pos_x + size_x <= game->background.size.x)
			game->character.current.position.x += game->character.current.size.x;
	}
	ft_printf("movement count: %u\n", game->character.movement_count += 1);
	ft_printf("Collectible count: %u/%u\n", game->character.collectibles_count, game->map.collectibles_number);
}

void	set_character(t_program *game)
{
	game->character.idle = new_sprite(game, "./assets/basic/parado.xpm");
	game->character.attacking = new_sprite(game, "./assets/basic/attacking.xpm");
	game->character.current = game->character.idle;
	game->character.movement_count = 0;
	game->character.collectibles_count= 0;
}

int	main(int argc, char *argv[])
{
	t_program	game;

	if (!validate_argv(argc, argv))
		exit(-1);
	game.map = generate_map(argv[1]);
	if (!validate_map(&game.map, argc, argv))
	{
		free(game.map.array);
		exit(-1);
	}
	print_map_status(&game.map);
	game.mlx = mlx_init();
	game.background = new_sprite(&game, "./assets/basic/floor.xpm");
	game.win = mlx_new_window(game.mlx, 1280, 720, "So Long");
	mlx_key_hook(game.win, key_hook, &game);
	set_character(&game);
	render_frame(&game);
	mlx_loop(game.mlx);
}
