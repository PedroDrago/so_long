/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 04:56:20 by pdrago            #+#    #+#             */
/*   Updated: 2023/11/30 17:11:48 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include "minilibx/mlx_int.h"
#include <stdlib.h> //malloc, free, exit
#include <unistd.h> //write, read, close
#include <fcntl.h> //open
#include <stdio.h> //perror
#include <string.h> //strerror
#include <math.h>

# ifndef PURPLE
#  define  PURPLE 0xB06FE5
# endif

# ifndef RED
#  define RED 0xFF1B1B
# endif

# ifndef GREEN
#  define GREEN 0x1FFF1B
# endif

# ifndef BLUE
#  define BLUE 0x1B24FF
# endif

# ifndef BLACK
#  define BLACK 0x000000
# endif

# ifndef WHITE
#  define WHITE 0xFFFFFF
# endif

# ifndef GRAY
#  define GRAY 0x898989
# endif

#endif
