/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 04:56:20 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/04 00:40:14 by pdrago           ###   ########.fr       */
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
# include <stdarg.h> //ft_printf
# include "macros.h"
# include "structs.h"
# include "../libft/libft.h"


int	exit_game(t_program *game, int status);
void	destroy_images(t_program *game);
void	destroy_map(t_map *map);

int		key_hook(int key, t_program *game);
int		validate_map(t_map *map);
int		validate_argv(int argc, char *argv[]);
int		check_map_characters(char *map[]);
int		get_map_size(char *map_file);
int		check_rectangular(t_map *map);
int		check_border_rows(t_map *map);
int		check_middle_rows(t_map *map);
int		check_surrounded(t_map *map);
int		check_path(t_map *map);
int		error_message(int error);
t_image	new_sprite(t_program *vars, char *path);
t_map	generate_map(char *map_file);
t_map	generate_map(char *map_file);
void	free_map(t_map *map);
void	check_win(t_program *game, t_map *map, t_character player);
void	change_to_right(t_character *character);
void	change_to_left(t_character *character);
void	change_to_down(t_character *character);
void	change_to_up(t_character *character);
void	set_collectibles_number(t_map *map);
void	print_map_status(t_map *map);
void	set_map_positions(t_map *map);
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

#endif
