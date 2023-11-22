/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 05:00:04 by pdrago            #+#    #+#             */
/*   Updated: 2023/11/22 20:08:30 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx-linux/mlx.h"
#include <stdio.h>

#define RES_X 1920
#define RES_Y 1080

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
	int	offset;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, RES_X, RES_Y, "Teste");
	img.img = mlx_new_image(mlx, RES_X, RES_Y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	int curr_x = 500;
	int curr_y = 0;
	while (curr_x < RES_X - 500)
			my_mlx_pixel_put(&img, curr_x++, 500, 0x48E448);
	curr_y = 150;
	while (curr_y < RES_Y - 150)
		my_mlx_pixel_put(&img, RES_X / 2, curr_y++, 0x48E448);
	mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
	mlx_loop(mlx);
}
