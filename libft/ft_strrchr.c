/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 21:57:14 by pdrago            #+#    #+#             */
/*   Updated: 2023/11/01 12:23:44 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The ft_strrchr() function returns a pointer to the last 
occurrence of the character c in the string s.
*/

char	*ft_strrchr(const char *s, int c)
{
	char	*ptrc;
	int		count;

	count = 0;
	ptrc = 0;
	while (s[count])
	{
		if (s[count] == c)
			ptrc = (char *) &s[count];
		count++;
	}
	if (s[count] == c)
		ptrc = (char *) &s[count];
	return (ptrc);
}
