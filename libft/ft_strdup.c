/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:38:29 by pdrago            #+#    #+#             */
/*   Updated: 2023/10/18 15:29:39 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
The ft_strdup() function returns a pointer to a new string which is a 
duplicate of the string s.  Memory for the new string is obtained with 
malloc(3), and can be freed with free(3).
*/

char	*ft_strdup(const char *s)
{
	char	*ret;
	int		count;

	ret = (char *) malloc (sizeof(char) * ft_strlen(s) + 1);
	if (!ret)
		return (NULL);
	count = 0;
	while (s[count])
	{
		ret[count] = s[count];
		count++;
	}
	ret[count] = '\0';
	return (ret);
}
