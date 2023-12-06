/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:56:19 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/05 22:57:52 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	validate_map(t_map *map, char *map_file)
{
	if (!map->array)
	{
		error_message(MAP_NOT_FOUND);
		exit(EXIT_FAILURE);
	}
	if (!check_map_characters(map->array))
		return (error_message(INVALID_CHARACTERS));
	if (!check_rectangular(map))
		return (error_message(MAP_NOT_RECTANGULAR));
	if (!check_surrounded(map))
		return (error_message(MAP_NOT_SURROUNDED));
	if (!check_path(map_file))
		return (error_message(NO_VALID_PATH));
	return (TRUE);
}

int	validate_argv(int argc, char *argv[])
{
	if (argc != 2)
		return (error_message(WRONG_ARGUMENTS));
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		return (error_message(WRONG_FILE_EXTENSION));
	return (TRUE);
}

int	error_message(int error)
{
	if (error == WRONG_ARGUMENTS)
		ft_putstr_fd("\e[31mError\nWrong number of \
arguments (expected 2)\n\e[0m", STDERR_FILENO);
	else if (error == WRONG_FILE_EXTENSION)
		ft_putstr_fd("\e[31mError\nMap has invalid \
extension (expecting .ber)\n\e[0m", STDERR_FILENO);
	else if (error == INVALID_CHARACTERS)
		ft_putstr_fd("\e[31mError\nMap has \
invalid characters.\n\e[0m", STDERR_FILENO);
	else if (error == MAP_NOT_RECTANGULAR)
		ft_putstr_fd("\e[31mError\n The map \
must be rectangular.\n\e[0m", STDERR_FILENO);
	else if (error == MAP_NOT_FOUND)
		ft_putstr_fd("\e[31mError\nThe map \
was not found.\n\e[0m", STDERR_FILENO);
	else if (error == MAP_NOT_SURROUNDED)
		ft_putstr_fd("\e[31mError\nThe map must \
be surrounded by walls.\n\e[0m", STDERR_FILENO);
	else if (error == NO_VALID_PATH)
		ft_putstr_fd("\e[31mError\nTHe map has no \
valid path for winning.\n\e[0m", STDERR_FILENO);
	return (FALSE);
}
