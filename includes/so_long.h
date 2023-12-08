/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 04:56:20 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/08 12:23:58 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include "../minilibx/mlx_int.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include "macros.h"
# include "structs.h"
# include "utils.h"


void	resolve_attack(t_character *player, t_map *map);
void	attack(t_character *player, t_map *map);
void	fill_with_enemies(t_map *map, int row, int column);
void	generate_enemies(t_map *map, int enemies_number);
void	exit_game_esc(t_program *game, int status);
void	set_map(t_map *map);


//finish the game executing, cleaning everything 
int		exit_game(t_program *game, int status);
//manage specific action for each key pressed
int		key_hook(int key, t_program *game);
//verify if current map is a valid map for playing
int		validate_map(t_map *map, char *map_file);
//verify if arguments are valid
int		validate_argv(int argc, char *argv[]);
//verify if map has valid characters
int		check_map_characters(char *map[]);
//returns map line count
int		get_map_size(char *map_file);
//verify if map is rectangular
int		check_rectangular(t_map *map);
//verify if first and last row are full of walls
int		check_border_rows(t_map *map);
//verify if middle map rows have walls in start and end
int		check_middle_rows(t_map *map);
//verify if all map borders are walls
int		check_surrounded(t_map *map);
//modify the map to be able to verify if a map is winnable
void	path_checker(char *map[], int x, int y);
//verify if map mas a valid path for winning
int		check_path(char *map_file);
//print error message based on error
int		error_message(int error);
//destroy map created in the program
int		destroy_map(t_map *map);
//generate a image object based on the image file
t_image	new_sprite(t_program *vars, char *path);
//generate a map object from the map file
t_map	generate_map(char *map_file);
//destroy all images created in the program
void	destroy_images(t_program *game);
//check if the player is in a win condition 
//(has all collectibles and is in the exit tile)
void	check_win(t_program *game, t_map *map, t_character player);
//count number of collectibles in map and store int in map object
void	set_collectibles_number(t_map *map);
//print current map array
void	print_map_status(t_map *map);
//register where are the map exit and entrance in the map object
void	set_map_positions(t_map *map);
//move character position in map 1 tile up if movement is valid
void	move_up(t_map *map, t_character *player);
//move character position in map 1 tile left if movement is valid
void	move_left(t_map *map, t_character *player);
//move character position in map 1 tile down if movement is valid
void	move_down(t_map *map, t_character *player);
//move character position in map 1 tile right if movement is valid
void	move_right(t_map *map, t_character *player);
//call the right movement function based on pressed key
void	resolve_movement(int key, t_program *game);
//print player movements and collectibles count
void	print_player_status(t_program *game);
//set all character properties includeing sprites, positions and counters
void	set_character(t_program *game);
//set all game object sprites 
void	set_sprites(t_program *game);
//render a tile based on cell character
void	render_tile(t_program *game, char object, t_coord pos);
//render the current map to screen
void	render_map(t_program *game);

#endif
