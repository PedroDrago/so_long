/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:42:07 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/03 07:53:09 by pdrago           ###   ########.fr       */
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
# ifndef COLLECTIBLE_PATH 
#  define COLLECTIBLE_PATH "./textures/collectible.xpm"
# endif

enum e_map_symbols
{
	ENTRANCE = 'P',
	EXIT = 'E',
	EMPTY = '0',
	WALL = '1',
	COLLECTIBLE = 'C',
	PLAYER = 'X'
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

enum e_colors
{
	PURPLE = 0xB06FE5,
	RED = 0xFF1B1B,
	GREEN = 0x1FFF1B,
	BLUE = 0x1B24FF,
	BLACK = 0x000000,
	WHITE = 0xFFFFFF,
	GRAY = 0x898989,
};

enum e_keys{
	ENTER = 65293,
	ESC = 65307,
	SPACE= 32,
	TAB = 65289,
	W = 119,
	A = 97,
	S = 115,
	D = 100,
	ARROW_UP = 65362,
	ARROW_DOWN = 65364,
	ARROW_RIGHT = 65363,
	ARROW_LEFT = 65361,
};

enum e_events
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
};

#endif
