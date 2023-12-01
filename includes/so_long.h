/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 04:56:20 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/01 00:52:16 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
#include <stdlib.h> //malloc, free, exit
#include <unistd.h> //write, read, close
#include <fcntl.h> //open
#include <stdio.h> //perror
#include <string.h> //strerror
#include <math.h>
#include <stdarg.h> //ft_printf
#include "enums.h"
#include "structs.h"
#include "../libft/libft.h"

int	key_hook(int key, t_program *game);
int validate_argv(int argc, char *argv[]);
t_image	new_sprite(t_program *vars, char *path);
t_image copy_sprite(t_program *game, t_image old);
void	render_frame(t_program *game);
void	change_to_attack(t_character *character);
void	change_to_idle(t_character *character);
void	resolve_movement(int key, t_program *game);
void	set_character_images(t_program *game);
#endif
