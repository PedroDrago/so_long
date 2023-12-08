/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:42:49 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/08 16:59:37 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

struct s_validations
{
	int	row;
	int	column;
	int	entrances;
	int	exits;
	int	collectibles;

};

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
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_coord	size;
	t_coord	position;
}	t_image;

typedef struct s_character
{
	int				dead;
	unsigned int	movement_count;
	unsigned int	collectibles_count;
	unsigned int	kill_count;
	t_image			down;
	t_image			up;
	t_image			right;
	t_image			left;
	t_image			current;
	t_image			up_door;
	t_image			down_door;
	t_image			left_door;
	t_image			right_door;
	t_image			attacking_grass;
	t_image			attacking_door;
	t_coord			array_indexes;
	t_coord			array_position;
}	t_character;

typedef struct s_numbers
{
	t_image	zero;
	t_image	one;
	t_image	two;
	t_image	three;
	t_image	four;
	t_image	five;
	t_image	six;
	t_image	seven;
	t_image	eight;
	t_image	nine;
}	t_numbers;

typedef struct s_map
{
	char			**array;
	unsigned int	collectibles_number;
	t_coord			array_size;
	t_coord			player_position;
	t_coord			exit_position;
}	t_map;

typedef struct s_exit
{
	t_image	open;
	t_image	closed;
	t_image	current;
}	t_exit;

typedef struct s_program
{
	t_character	character;
	void		*mlx;
	void		*win;
	t_exit		exit;
	t_coord		exit_position_pixel;
	t_map		map;
	t_image		background;
	t_image		wall;
	t_image		collectible;
	t_image		victory;
	t_image		enemy;
	t_numbers	numbers;
}	t_program;
#endif
