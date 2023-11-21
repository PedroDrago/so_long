/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:45:41 by pdrago            #+#    #+#             */
/*   Updated: 2023/11/01 12:24:33 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The ft_bzero() function erases the data in the n bytes of the 
memory starting at the location pointed to 
by s, by writing zeros (bytes containing '\0') to that area.
*/

void	ft_bzero(void *s, size_t n)
{
	size_t	count;
	char	*ptr;

	ptr = (char *) s;
	count = -1;
	while (++count < n)
		ptr[count] = 0;
}
