#include "../includes/so_long.h"

int	key_hook(int key, t_program *game)
{
	if (key == ESC)
		exit(0);
	else if (key == W || key == A || key == S || key == D)
		resolve_movement(key, game);
	else if (key == SPACE)
		change_to_attack(&game->character);
	render_frame(game);
	// ft_printf("character x: %i\n", game->character.idle.position.x);
	// ft_printf("character y: %i\n", game->character.idle.position.y);
	return (0);
}
