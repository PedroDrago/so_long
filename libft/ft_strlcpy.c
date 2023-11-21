/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:08:47 by pdrago            #+#    #+#             */
/*   Updated: 2023/10/18 15:23:36 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Copies up to size - 1 characters from the NUL-terminated source 
string to a destine string, NUL-terminating the result.
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char		*end;
	const char	*start;

	if (size == 0)
		return (ft_strlen(src));
	end = dst + size;
	start = src;
	while (*start != '\0' && dst < end)
	{
		*dst = *start;
		dst++;
		start++;
	}
	if (dst < end)
		*dst = 0;
	else if (size > 0)
		dst[-1] = 0;
	while (*start != '\0')
		start++;
	return (ft_strlen(src));
}
