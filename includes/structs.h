/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:42:49 by pdrago            #+#    #+#             */
/*   Updated: 2023/11/30 23:42:51 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;


typedef struct s_image
{
	void	*img;
	char	*addr;
	char	*path;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
	t_coord size;
	t_coord position;
}	t_image;

typedef struct s_character
{
	t_image idle;
	t_image attacking;
	t_image current;
	unsigned int	movement_count;
}	t_character;

typedef struct s_program
{
	void *mlx;
	void *win;
	t_character character;
	t_image background;
}	t_program;
