#include "../includes/so_long.h"

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
	game.win = mlx_new_window(game.mlx, game.map.array_size.x * TILE_SIZE,
			game.map.array_size.y * TILE_SIZE, "So Long");
	mlx_key_hook(game.win, key_hook, &game);
	set_sprites(&game);
	mlx_loop(game.mlx);
}
