/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 05:00:04 by pdrago            #+#    #+#             */
/*   Updated: 2023/11/27 00:58:26 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"
#include <stdio.h>

#define RES_X 1280
#define RES_Y 720

typedef struct s_data
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
int	main(void)
{
	void	*mlx;
	void	*mlx_window;
	t_data	img;
	t_data	img2;
	int	color;
	int	count;
	int	offset;

	mlx = mlx_init();
	color = 0x48E448;
	count = 0;
	mlx_window = mlx_new_window(mlx, RES_X, RES_Y, "Teste");
	img.img = mlx_new_image(mlx, RES_X, RES_Y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	int x = 500;
	int y = 500;
	int x2 = x;
	int y2 = y;
	while (x < 600 && y < 600)
	{
		my_mlx_pixel_put(&img, x++, y++, color);
	}
	// while (y < RES_Y)
	// {
	// 	x = 0;
	// 	while (x < RES_X)
	// 	{
	// 		my_mlx_pixel_put(&img, x, y, color);
	// 		x++;
	// 	}
	// 	y++;
	// 	count++;
	// 	if (count == 4)
	// 	{
	// 		color++;
	// 		count = 0;
	// 	}
	// }
	mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
	mlx_loop(mlx);
}
