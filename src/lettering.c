/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lettering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:43:47 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/09 23:30:05 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	choose_char(char c)
{
	if (c == '0')
		return (ZERO);
	else if (c == '1')
		return (ONE);
	return (c);
}

void	set_movement_letters(t_map *map, char *number)
{
	int	row;
	int	column;

	column = 0;
	row = map->array_size.y - 1;
	while (map->array[row][column] && number[column])
	{
		map->array[row][column] = choose_char(number[column]);
		column++;
	}
}

void	set_collectible_letters(t_map *map, char *number)
{
	int		row;
	int		column;
	int		str_index;
	char	*max_colect;

	column = 0;
	row = 0;
	max_colect = ft_itoa(map->collectibles_number);
	while (map->array[row][column] && number[column])
	{
		map->array[row][column] = choose_char(number[column]);
		column++;
	}
	map->array[row][column++] = SLASH;
	while (map->array[row][column] && max_colect[str_index])
	{
		map->array[row][column] = choose_char(max_colect[str_index]);
		column++;
		str_index++;
	}
	free(max_colect);
}

void	do_letters(t_map *map, t_character *player)
{
	char	*number;

	number = ft_itoa(player->movement_count);
	if ((int) ft_strlen(number) < map->array_size.x)
		set_movement_letters(map, number);
	free (number);
	number = ft_itoa(player->collectibles_count);
	if ((int) ft_strlen(number) < map->array_size.x)
		set_collectible_letters(map, number);
	free(number);
}
