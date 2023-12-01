/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 01:41:56 by pdrago            #+#    #+#             */
/*   Updated: 2023/11/21 01:42:14 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*joined;
	int		count;

	joined = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joined)
		return (NULL);
	count = 0;
	if (s1)
	{
		while (s1[count])
		{
			joined[count] = s1[count];
			count++;
		}
		free (s1);
	}
	while (*s2)
		joined[count++] = *s2++;
	joined[count] = '\0';
	if (!(*joined))
	{
		free (joined);
		return (NULL);
	}
	return (joined);
}
