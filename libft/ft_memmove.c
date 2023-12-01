/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 08:39:29 by pdrago            #+#    #+#             */
/*   Updated: 2023/11/01 12:25:10 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Copies n bytes from a source memory area to a destine 
memory area. The areas may overlap.
*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		count;
	char	*srcpy;
	char	*destcpy;

	srcpy = (char *) src;
	destcpy = (char *) dest;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		count = n - 1;
		while (count >= 0)
		{
			destcpy[count] = srcpy[count];
			count--;
		}
	}
	else
	{
		count = -1;
		while (++count < (int) n)
			destcpy[count] = srcpy[count];
	}
	return (dest);
}
