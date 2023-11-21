/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 21:46:33 by pdrago            #+#    #+#             */
/*   Updated: 2023/10/12 08:53:56 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The  ft_strncmp()  function compares the two strings s1 and s2, but 
it compares only the first (at most) n bytes of s1 and s2.  

       ft_strncmp() returns an integer indicating the result 
       of the comparison, as follows:
       - 0, if the s1 and s2 are equal;
       - a negative value if s1 is less than s2;
       - a positive value if s1 is greater than s2.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	count;

	count = 0;
	if (n == 0)
		return (0);
	while ((((unsigned char) s1[count]) == ((unsigned char) s2[count]))
		&& (s1[count]) && (s2[count]) && (--n))
		count++;
	return ((unsigned char) s1[count] - (unsigned char) s2[count]);
}
