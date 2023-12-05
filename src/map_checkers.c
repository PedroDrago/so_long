/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:35:12 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/05 15:35:13 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_map_characters(char *map[])
{
	struct s_validations	vars;

	vars.entrances = 0;
	vars.exits = 0;
	vars.row = -1;
	vars.collectibles = 0;
	while (map[++vars.row])
	{
		vars.column = -1;
		while (map[vars.row][++vars.column])
		{
			if (!ft_strchr("01CEP\n", map[vars.row][vars.column]))
				return (FALSE);
			if (map[vars.row][vars.column] == ENTRANCE)
				vars.entrances++;
			else if (map[vars.row][vars.column] == EXIT)
				vars.exits++;
			else if (map[vars.row][vars.column] == COLLECTIBLE)
				vars.collectibles++;
		}
	}
	if (vars.entrances != 1 || vars.exits != 1 || vars.collectibles < 1)
		return (FALSE);
	return (TRUE);
}

int	check_rectangular(t_map *map)
{
	int	row;
	int	column;
	int	row_size;

	row = -1;
	row_size = 0;
	while (map->array[++row])
	{
		column = -1;
		while (map->array[row][++column])
		{
			continue ;
		}
		if (row == 0)
			row_size = column;
		else if (column != row_size)
			return (FALSE);
	}
	if (row == column || row <= 2 || column <= 2)
		return (FALSE);
	map->array_size.x = column;
	map->array_size.y = row;
	return (TRUE);
}

int	check_border_rows(t_map *map)
{
	int	row;
	int	column;

	row = 0;
	while (map->array[row])
	{
		column = -1;
		while (map->array[row][++column])
		{
			if (!ft_strchr("1", map->array[row][column]))
				return (FALSE);
		}
		if (row++ == 0)
			row = map->array_size.y - 1;
	}
	return (TRUE);
}

int	check_middle_rows(t_map *map)
{
	int	row;

	row = 0;
	while (++row < map->array_size.y - 1)
	{
		if (map->array[row][0] != '1'
			|| map->array[row][map->array_size.x - 1] != '1')
			return (FALSE);
	}
	return (TRUE);
}

int	check_surrounded(t_map *map)
{
	if (!check_border_rows(map))
		return (FALSE);
	else if (!check_middle_rows(map))
		return (FALSE);
	return (TRUE);
}
