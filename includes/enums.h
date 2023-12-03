/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 23:42:07 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/03 05:01:59 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
