#include "so_long.h"
#include "minilibx/mlx.h"
#include <stdio.h>
#include <unistd.h>

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,



	ENTER = 65293,
	ESC = 65307,
	SPACE= 32,
	TAB = 65289,
	W = 119,
	A = 97,
	S = 115,
	D = 100,
	ARROW_UP = 65362,
	ARROW_DOWN = 65364,
	ARROW_RIGHT = 65363,
	ARROW_LEFT = 65361,
};

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;


typedef struct s_image
{
	void	*img;
	char	*addr;
	t_coord size;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
	t_coord position;
	char	*path;
}	t_image;

typedef struct s_character
{
	t_image idle;
	t_image attacking;
	t_image current;
	unsigned int	movement_count;
}	t_character;

typedef struct s_program
{
	void *mlx;
	void *win;
	t_character character;
	t_image background;
	int	x;
	int	y;
}	t_program;


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
	printf("movement count: %u\n", game->character.movement_count += 1);
}
int	key_hook(int key, t_program *game)
{
	if (key == ESC)
		exit(0);
	else if (key == W || key == A || key == S || key == D)
		resolve_movement(key, game);
	else if (key == SPACE)
		change_to_attack(&game->character);
	render_frame(game);
	printf("character x: %i\n", game->character.idle.position.x);
	printf("character y: %i\n", game->character.idle.position.y);
	return (0);
}

void	set_character_images(t_program *game)
{
	game->character.idle = new_sprite(game, "./assets/basic/parado.xpm");
	game->character.attacking = new_sprite(game, "./assets/basic/attacking.xpm");
	game->character.current = game->character.idle;
	game->character.movement_count = 0;
}

int	main(void)
{
	t_program	game;
	t_image character_sprite;
	t_image	background;

	game.mlx = mlx_init();
	game.background = new_sprite(&game, "./assets/basic/background.xpm");
	game.win = mlx_new_window(game.mlx, game.background.size.x, game.background.size.y, "So Long");
	mlx_key_hook(game.win, key_hook, &game);
	set_character_images(&game);
	render_frame(&game);
	mlx_loop(game.mlx);
}
