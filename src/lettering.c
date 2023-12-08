/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lettering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:43:47 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/08 16:43:48 by pdrago           ###   ########.fr       */
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
	int	column;
	int	count;

	count = 0;
	column = map->array_size.y - 1;
	while (map->array[column][count] && number[count])
	{
		map->array[column][count] = choose_char(number[count]);
		count++;
	}
}

void	set_collectible_letters(t_map *map, char *number)
{
	int	column;
	int	count;

	count = 0;
	column = 0;
	while (map->array[column][count] && number[count])
	{
		map->array[column][count] = choose_char(number[count]);
		count++;
	}
}
