/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:35:27 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/05 15:35:28 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_tile(t_program *game, char object, t_coord pos)
{
	if (object == EMPTY)
		mlx_put_image_to_window(game->mlx, game->win,
			game->background.img, pos.x, pos.y);
	else if (object == WALL)
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall.img, pos.x, pos.y);
	else if (object == COLLECTIBLE)
		mlx_put_image_to_window(game->mlx, game->win,
			game->collectible.img, pos.x, pos.y);
	else if (object == EXIT)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit.current.img, pos.x, pos.y);
		game->exit_position_pixel.x = pos.x;
		game->exit_position_pixel.y = pos.y;
	}
	else if (object == ENTRANCE || object == PLAYER)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->character.current.img, pos.x, pos.y);
	}
}

void	render_map(t_program *game)
{
	int		row;
	int		column;
	t_coord	pos;

	row = 0;
	pos.x = 0;
	pos.y = 0;
	while (game->map.array[row])
	{
		column = 0;
		pos.x = 0;
		while (game->map.array[row][column])
		{
			render_tile(game, game->map.array[row][column], pos);
			column++;
			pos.x += TILE_SIZE;
		}
		row++;
		pos.y += TILE_SIZE;
	}
}
