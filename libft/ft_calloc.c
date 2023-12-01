/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 03:27:11 by pdrago            #+#    #+#             */
/*   Updated: 2023/10/27 08:40:43 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The calloc() function allocates memory for an array of nmemb elements 
of  size  bytes each  and  returns a pointer to the allocated memory.  
The memory is set to zero. If nmemb or size is 0, then calloc() returns 
either NULL, or a unique pointer value that can  later be successfully passed 
to free().  If the multiplication of nmemb and size would result in integer 
overflow, then calloc() returns an error.
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*allocation;

	if (nmemb == 0 || size == 0)
	{
		allocation = malloc (1);
		return (allocation);
	}
	allocation = malloc (nmemb * size);
	if (!allocation)
		return (NULL);
	ft_bzero(allocation, (nmemb * size));
	return (allocation);
}
