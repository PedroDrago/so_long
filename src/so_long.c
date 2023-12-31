/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:56:13 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/09 23:40:09 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_program	game;

	if (!validate_argv(argc, argv))
		exit(EXIT_FAILURE);
	game.map = generate_map(argv[1]);
	if (!validate_map(&game.map, argv[1]))
		exit(destroy_map(&game.map));
	set_map(&game.map);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map.array_size.x * TILE_SIZE,
			game.map.array_size.y * TILE_SIZE, "So Long");
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, DestroyNotify, StructureNotifyMask,
		exit_game_cross, &game); //verify leaks from closing with cross, and won/loose message
	set_sprites(&game);
	mlx_loop(game.mlx);
}
