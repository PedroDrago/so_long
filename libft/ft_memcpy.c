/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:31:01 by pdrago            #+#    #+#             */
/*   Updated: 2023/11/01 12:25:04 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The  ft_memcpy()  function copies n bytes from memory area 
src to memory area dest.  The memory areas must not overlap.
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			count;
	char			*ptr_dest;
	const char		*ptr_src;

	if (!dest && !src)
		return (NULL);
	ptr_dest = (char *) dest;
	ptr_src = (const char *) src;
	count = -1;
	while (++count < n)
		ptr_dest[count] = ptr_src[count];
	return (dest);
}
