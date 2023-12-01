/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:42:49 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/01 11:56:28 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_border
{
	int	up;
	int	left;
	int	down;
	int	right;
}	t_border;

typedef struct s_image
{
	void	*img;
	char	*addr;
	char	*path;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
	t_coord size;
	t_border border;
	t_coord position;
}	t_image;

typedef struct s_character
{
	t_image idle;
	t_image attacking;
	t_image current;
	t_coord array_indexes;
	unsigned int	movement_count;
	unsigned int	collectibles_count;
}	t_character;

typedef struct s_map
{
	char	**array;
	t_coord	array_size;
	int	collectibles_number;
}	t_map;

typedef struct s_program
{
	void *mlx;
	void *win;
	t_character character;
	t_image background;
	t_map map;
}	t_program;
