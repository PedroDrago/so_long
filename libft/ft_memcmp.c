/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 21:20:17 by pdrago            #+#    #+#             */
/*   Updated: 2023/10/18 00:13:40 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The  ft_memcmp() function returns an integer less than, equal 
to, or greater than zero if the first n bytes of s1 is found, 
respectively, to be less than, to match, or be greater than the 
first n bytes of s2.

For a nonzero return value, the sign is determined by the sign of the 
difference between the first pair of bytes (interpreted as unsigned char) 
that differ in s1 and s2.

If n is zero, the return value is zero.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*ptr1;
	char	*ptr2;
	size_t	count;

	count = 0;
	ptr1 = (char *)s1;
	ptr2 = (char *)s2;
	while (count < n)
	{
		if (ptr1[count] != ptr2[count])
			return ((unsigned char)ptr1[count] - (unsigned char)ptr2[count]);
		count++;
	}
	return (0);
}
