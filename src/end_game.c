/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:57:26 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/08 16:44:48 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	destroy_map(t_map *map)
{
	int	count;

	count = 0;
	while (map->array[count])
		free(map->array[count++]);
	free(map->array[count++]);
	free(map->array);
	return (EXIT_FAILURE);
}

void	destroy_character(t_program *game)
{
	mlx_destroy_image(game->mlx, game->character.up.img);
	mlx_destroy_image(game->mlx, game->character.up_door.img);
	mlx_destroy_image(game->mlx, game->character.down.img);
	mlx_destroy_image(game->mlx, game->character.down_door.img);
	mlx_destroy_image(game->mlx, game->character.left.img);
	mlx_destroy_image(game->mlx, game->character.left_door.img);
	mlx_destroy_image(game->mlx, game->character.right.img);
	mlx_destroy_image(game->mlx, game->character.right_door.img);
	mlx_destroy_image(game->mlx, game->character.attacking_door.img);
	mlx_destroy_image(game->mlx, game->character.attacking_grass.img);
}

void	destroy_images(t_program *game)
{
	destroy_character(game);
	mlx_destroy_image(game->mlx, game->exit.open.img);
	mlx_destroy_image(game->mlx, game->exit.closed.img);
	mlx_destroy_image(game->mlx, game->wall.img);
	mlx_destroy_image(game->mlx, game->victory.img);
	mlx_destroy_image(game->mlx, game->background.img);
	mlx_destroy_image(game->mlx, game->collectible.img);
	mlx_destroy_image(game->mlx, game->enemy.img);
	mlx_destroy_image(game->mlx, game->numbers.zero.img);
	mlx_destroy_image(game->mlx, game->numbers.one.img);
	mlx_destroy_image(game->mlx, game->numbers.two.img);
	mlx_destroy_image(game->mlx, game->numbers.three.img);
	mlx_destroy_image(game->mlx, game->numbers.four.img);
	mlx_destroy_image(game->mlx, game->numbers.five.img);
	mlx_destroy_image(game->mlx, game->numbers.six.img);
	mlx_destroy_image(game->mlx, game->numbers.seven.img);
	mlx_destroy_image(game->mlx, game->numbers.eight.img);
	mlx_destroy_image(game->mlx, game->numbers.nine.img);
}

void	exit_game_esc(t_program *game, int status)
{
	game->character.dead = TRUE;
	exit_game(game, status);
}

int	exit_game(t_program *game, int status)
{
	destroy_map(&game->map);
	destroy_images(game);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	if (game->character.dead)
		ft_printf("\e[31mYou loose!\n\e[0m");
	else
		ft_printf("\e[32mYou won!\n\e[0m");
	exit (status);
	return (status);
}
