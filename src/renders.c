/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:56:44 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/09 23:19:54 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	doi(void *mlx_ptr, void *win_ptr, void *img_ptr, t_coord pos)
{
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, pos.x, pos.y);
}

void	resolve_letters(t_program *game, char object, t_coord pos)
{
	if (object == ZERO)
		doi(game->mlx, game->win, game->numbers.zero.img, pos);
	else if (object == ONE)
		doi(game->mlx, game->win, game->numbers.one.img, pos);
	else if (object == TWO)
		doi(game->mlx, game->win, game->numbers.two.img, pos);
	else if (object == THREE)
		doi(game->mlx, game->win, game->numbers.three.img, pos);
	else if (object == FOUR)
		doi(game->mlx, game->win, game->numbers.four.img, pos);
	else if (object == FIVE)
		doi(game->mlx, game->win, game->numbers.five.img, pos);
	else if (object == SIX)
		doi(game->mlx, game->win, game->numbers.six.img, pos);
	else if (object == SEVEN)
		doi(game->mlx, game->win, game->numbers.seven.img, pos);
	else if (object == EIGHT)
		doi(game->mlx, game->win, game->numbers.eight.img, pos);
	else if (object == NINE)
		doi(game->mlx, game->win, game->numbers.nine.img, pos);
	else if (object == SLASH)
		doi(game->mlx, game->win, game->numbers.slash.img, pos);
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
