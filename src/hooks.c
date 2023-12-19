/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:57:22 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/19 08:44:53 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_end(t_program *game, t_map *map, t_character player)
{
	if ((map->player_position.x == map->exit_position.x
			&& map->player_position.y == map->exit_position.y
			&& player.collectibles_count == map->collectibles_number)
		|| (player.dead))
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->victory.img,
			game->exit_position_pixel.x,
			game->exit_position_pixel.y);
		exit_game(game, EXIT_SUCCESS);
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

void	print_player_status(t_program *game)
{
	ft_printf("movement count: %u\n",
		game->character.movement_count);
	ft_printf("Collectible count: %u/%u\n",
		game->character.collectibles_count, game->map.collectibles_number);
	ft_printf("Kill count: %u\n", game->character.kill_count);
}

int	key_hook(int key, t_program *game)
{
	if (key == ESC)
	{
		game->character.dead = TRUE;
		exit_game(game, EXIT_SUCCESS);
	}
	else if (key == W || key == A || key == S || key == D
		|| key == ARROW_UP || key == ARROW_DOWN
		|| key == ARROW_LEFT || key == ARROW_RIGHT)
		resolve_movement(key, game);
	else if (key == SPACE)
		attack(&game->character, &game->map);
	render_map(game);
	print_player_status(game);
	check_collectibles(game);
	check_end(game, &game->map, game->character);
	return (0);
}
