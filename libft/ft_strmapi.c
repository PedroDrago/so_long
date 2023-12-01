/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:18:24 by pdrago            #+#    #+#             */
/*   Updated: 2023/10/17 12:53:21 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Applies the function ’f’ to each character of the
string ’s’, and passing its index as first argument
to create a new string (with malloc(3)) resulting
from successive applications of ’f’.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*map;
	unsigned int	count;

	count = 0;
	map = (char *) malloc (sizeof(char) * (ft_strlen(s) + 1));
	if (!map)
		return (NULL);
	while (s[count])
	{
		map[count] = f(count, s[count]);
		count++;
	}
	map[count] = '\0';
	return (map);
}
