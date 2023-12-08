/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:56:44 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/08 14:44:28 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	resolve_letters(t_program *game, char object, t_coord pos)
{
	if (object == ZERO)
		mlx_put_image_to_window(game->mlx, game->win, game->numbers.zero.img, pos.x, pos.y);
	else if (object == ONE)
		mlx_put_image_to_window(game->mlx, game->win, game->numbers.one.img, pos.x, pos.y);
	else if (object == TWO)
		mlx_put_image_to_window(game->mlx, game->win, game->numbers.two.img, pos.x, pos.y);
	else if (object == THREE)
		mlx_put_image_to_window(game->mlx, game->win, game->numbers.three.img, pos.x, pos.y);
	else if (object == FOUR)
		mlx_put_image_to_window(game->mlx, game->win, game->numbers.four.img, pos.x, pos.y);
	else if (object == FIVE)
		mlx_put_image_to_window(game->mlx, game->win, game->numbers.five.img, pos.x, pos.y);
	else if (object == SIX)
		mlx_put_image_to_window(game->mlx, game->win, game->numbers.six.img, pos.x, pos.y);
	else if (object == SEVEN)
		mlx_put_image_to_window(game->mlx, game->win, game->numbers.seven.img, pos.x, pos.y);
	else if (object == EIGHT)
		mlx_put_image_to_window(game->mlx, game->win, game->numbers.eight.img, pos.x, pos.y);
	else if (object == NINE)
		mlx_put_image_to_window(game->mlx, game->win, game->numbers.nine.img, pos.x, pos.y);
}

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
		mlx_put_image_to_window(game->mlx, game->win,
			game->character.current.img, pos.x, pos.y);
	else if (object == ENEMY)
		mlx_put_image_to_window(game->mlx, game->win,
			game->enemy.img, pos.x, pos.y);
	else
		resolve_letters(game, object, pos);
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
