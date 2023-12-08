/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:42:07 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/08 12:08:29 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H 
# define MACROS_H

# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif
# ifndef FROG_UP_PATH
#  define FROG_UP_PATH "./textures/frog/up.xpm"
# endif
# ifndef FOG_UP_DOOR_PATH
#  define FROG_UP_DOOR_PATH "./textures/frog/up_door.xpm"
# endif
# ifndef FROG_DOWN_PATH
#  define FROG_DOWN_PATH "./textures/frog/down.xpm"
# endif
# ifndef FROG_DOWN_DOOR_PATH
#  define FROG_DOWN_DOOR_PATH "./textures/frog/down_door.xpm"
# endif
# ifndef FROG_LEFT_PATH
#  define FROG_LEFT_PATH "./textures/frog/left.xpm"
# endif
# ifndef FROG_LEFT_DOOR_PATH
#  define FROG_LEFT_DOOR_PATH "./textures/frog/left_door.xpm"
# endif
# ifndef FROG_RIGHT_PATH
#  define FROG_RIGHT_PATH "./textures/frog/right.xpm"
# endif
# ifndef FROG_RIGHT_DOOR_PATH
#  define FROG_RIGHT_DOOR_PATH "./textures/frog/right_door.xpm"
# endif
# ifndef BACKGROUND_PATH
#  define BACKGROUND_PATH "./textures/terrain/floor_tile.xpm"
# endif
# ifndef WALL_PATH
#  define WALL_PATH "./textures/terrain/wall.xpm"
# endif
# ifndef EXIT_OPEN_PATH 
#  define EXIT_OPEN_PATH "./textures/terrain/exit_open.xpm"
# endif
# ifndef EXIT_CLOSED_PATH
#  define EXIT_CLOSED_PATH "./textures/terrain/exit_closed.xpm"
# endif
# ifndef VICTORY_PATH
#  define VICTORY_PATH "./textures/frog/victory.xpm"
# endif
# ifndef ATTACKING_PATH
#  define ATTACKING_PATH "./textures/frog/attacking.xpm"
# endif
# ifndef COLLECTIBLE_PATH 
#  define COLLECTIBLE_PATH "./textures/collectible/collectible.xpm"
# endif
# ifndef ENEMY_PATH
#  define ENEMY_PATH "./textures/enemy/enemy.xpm"
# endif
# ifndef TRUE
#  define TRUE 1
# endif
# ifndef FALSE
#  define FALSE 0
# endif

enum e_map_symbols
{
	ENTRANCE = 'P',
	EXIT = 'E',
	EMPTY = '0',
	WALL = '1',
	COLLECTIBLE = 'C',
	PLAYER = 'X',
	ENEMY = 'G'
};

enum e_errors
{
	WRONG_ARGUMENTS = 0,
	WRONG_FILE_EXTENSION = 1,
	INVALID_CHARACTERS = 2,
	MAP_NOT_RECTANGULAR = 3,
	MAP_NOT_FOUND = 4,
	MAP_NOT_SURROUNDED = 5,
	NO_VALID_PATH = 6,
};

enum e_keys{
	ESC = 65307,
	W = 119,
	A = 97,
	S = 115,
	D = 100,
	SPACE = 32,
	ARROW_UP = 65362,
	ARROW_DOWN = 65364,
	ARROW_RIGHT = 65363,
	ARROW_LEFT = 65361,
};
#endif
