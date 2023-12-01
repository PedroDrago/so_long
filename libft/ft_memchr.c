/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 23:01:10 by pdrago            #+#    #+#             */
/*   Updated: 2023/10/17 13:26:38 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The  ft_memchr() function scans the initial n bytes of the memory area 
pointed to by s for the first instance of c.  Both c and the bytes of 
the memory area pointed to by s are interpreted as unsigned char.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ptr_s;
	size_t	count;

	ptr_s = (char *) s;
	count = 0;
	while (count < n)
	{
		if (ptr_s[count] == c)
			return ((void *) s + count);
		count++;
	}
	return (NULL);
}
