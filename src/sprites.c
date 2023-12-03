#include "../includes/so_long.h"

t_image	new_sprite(t_program *vars, char *path)
{
	t_image	sprite;

	sprite.img = mlx_xpm_file_to_image(vars->mlx, path,
			&sprite.size.x, &sprite.size.y);
	sprite.addr = mlx_get_data_addr(sprite.img,
			&sprite.bits_per_pixel, &sprite.line_length, &sprite.endian);
	sprite.position.x = 0;
	sprite.position.y = 0;
	sprite.path = path;
	return (sprite);
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
	game->character.collectibles_count = 0;
	game->character.array_position.x = 0;
	game->character.array_position.y = 0;
}

void	set_exit(t_program *game)
{
	game->exit.closed = new_sprite(game, EXIT_CLOSED_PATH);
	game->exit.open = new_sprite(game, EXIT_OPEN_PATH);
	game->exit.current = game->exit.closed;
}

void	set_sprites(t_program *game)
{
	set_exit(game);
	set_character(game);
	game->collectible = new_sprite(game, COLLECTIBLE_PATH);
	game->background = new_sprite(game, BACKGROUND_PATH);
	game->victory = new_sprite(game, VICTORY_PATH);
	game->wall = new_sprite(game, WALL_PATH);
}
