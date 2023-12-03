/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 04:56:20 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/03 05:52:14 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
# include <stdlib.h> //malloc, free, exit
# include <unistd.h> //write, read, close
# include <fcntl.h> //open
# include <stdio.h> //perror
# include <string.h> //strerror
# include <math.h>
# include <stdarg.h> //ft_printf
# include "enums.h"
# include "structs.h"
# include "../libft/libft.h"

# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif

# define FROG_UP_PATH "./textures/frog/up.xpm"
# define FROG_UP_DOOR_PATH "./textures/frog/up_door.xpm"
# define FROG_DOWN_PATH "./textures/frog/down.xpm"
# define FROG_DOWN_DOOR_PATH "./textures/frog/down_door.xpm"
# define FROG_LEFT_PATH "./textures/frog/left.xpm"
# define FROG_LEFT_DOOR_PATH "./textures/frog/left_door.xpm"
# define FROG_RIGHT_PATH "./textures/frog/right.xpm"
# define FROG_RIGHT_DOOR_PATH "./textures/frog/right_door.xpm"
# define BACKGROUND_PATH "./textures/terrain/floor_tile.xpm"
# define WALL_PATH "./textures/terrain/wall.xpm"
# define EXIT_OPEN_PATH "./textures/terrain/exit_open.xpm"
# define EXIT_CLOSED_PATH "./textures/terrain/exit_closed.xpm"
# define VICTORY_PATH "./textures/frog/victory.xpm"
# define COLLECTIBLE_PATH "./textures/collectible.xpm"


void	check_win(t_program *game, t_map *map, t_character player,int y, int x);


void	change_to_right(t_character *character);
void	change_to_left(t_character *character);
void	change_to_down(t_character *character);
void	change_to_up(t_character *character);
// void	check_win(t_map *map, t_character player,int y, int x);
int	key_hook(int key, t_program *game);
int validate_map(t_map *map, int argc, char *argv[]);
int validate_argv(int argc, char *argv[]);
int	check_map_characters(char *map[]);
int	get_map_size(char *map_file);
t_map	generate_map(char *map_file);
int	error_message(int error, int argc, char *argv[]);
void	set_collectibles_number(t_map *map);
int	check_rectangular(t_map *map);
int	check_border_rows(t_map *map);
int	check_middle_rows(t_map *map);
int	check_surrounded(t_map *map);
int	check_path(t_map *map);
void	print_map_status(t_map *map);
void	set_map_positions(t_map *map);
t_image	new_sprite(t_program *vars, char *path);
void	render_frame(t_program *game);
void	change_to_attack(t_character *character);
void	change_to_idle(t_character *character);
void	move_up(t_map *map, t_character *player);
void	move_left(t_map *map, t_character *player);
void	move_down(t_map *map, t_character *player);
void	move_right(t_map *map, t_character *player);
void	resolve_movement(int key, t_program *game);
void	set_character(t_program *game);
void	set_sprites(t_program *game);
void	render_tile(t_program *game, char object, t_coord pos);
void	render_map(t_program *game);
void	exit_game(t_program *game);

#endif
