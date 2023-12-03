#include "../includes/so_long.h"

void	check_win(t_program *game, t_map *map, t_character player,int y, int x)
{
	if (map->player_position.x == map->exit_position.x && map->player_position.y == map->exit_position.y && player.collectibles_count == map->collectibles_number)
	{
		mlx_put_image_to_window(game->mlx, game->win, game->victory.img, game->exit_position_pixel.x, game->exit_position_pixel.y);
	}
}

void	check_collectibles(t_program *game)
{
	if (game->character.collectibles_count == game->map.collectibles_number)
	{
		game->exit.current = game->exit.open;
		render_map(game);
	}
}

int	key_hook(int key, t_program *game)
{
	if (key == ESC)
		exit(0);
	else if (key == W || key == A || key == S || key == D)
		resolve_movement(key, game);
	render_map(game);
	check_collectibles(game);
	check_win(game, &game->map, game->character ,game->map.player_position.y, game->map.player_position.x);
	// ft_printf("character x: %i\n", game->character.idle.position.x);
	// ft_printf("character y: %i\n", game->character.idle.position.y);
	return (0);
}











// int	key_hook(int key, t_program *game)
// {
// 	if (key == ESC)
// 		exit(0);
// 	else if (key == W || key == A || key == S || key == D)
// 		resolve_movement(key, game);
// 	// render_frame(game);
// 	render_map(game);
// 	check_collectibles(&game, &char);
// 	check_win(&game->map, game->character ,game->map.player_position.y, game->map.player_position.x);
// 	// ft_printf("character x: %i\n", game->character.idle.position.x);
// 	// ft_printf("character y: %i\n", game->character.idle.position.y);
// 	return (0);
// }
























