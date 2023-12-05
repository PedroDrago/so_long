#include "../includes/so_long.h"

int	destroy_map(t_map *map)
{
	int	count;

	count = 0;
	while (count <= map->array_size.y)
		free(map->array[count++]);
	free(map->array);
	return (EXIT_FAILURE);
}

void	destroy_images(t_program *game)
{
	mlx_destroy_image(game->mlx, game->character.up.img);
	mlx_destroy_image(game->mlx, game->character.up_door.img);
	mlx_destroy_image(game->mlx, game->character.down.img);
	mlx_destroy_image(game->mlx, game->character.down_door.img);
	mlx_destroy_image(game->mlx, game->character.left.img);
	mlx_destroy_image(game->mlx, game->character.left_door.img);
	mlx_destroy_image(game->mlx, game->character.right.img);
	mlx_destroy_image(game->mlx, game->character.right_door.img);
	mlx_destroy_image(game->mlx, game->exit.open.img);
	mlx_destroy_image(game->mlx, game->exit.closed.img);
	mlx_destroy_image(game->mlx, game->wall.img);
	mlx_destroy_image(game->mlx, game->victory.img);
	mlx_destroy_image(game->mlx, game->background.img);
	mlx_destroy_image(game->mlx, game->collectible.img);
}

int	exit_game(t_program *game, int status)
{
	destroy_map(&game->map);
	destroy_images(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit (status);
	return (status);
}
