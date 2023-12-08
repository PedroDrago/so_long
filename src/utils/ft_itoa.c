/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:28:56 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/08 13:29:38 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static unsigned int	count_len(int number)
{
	unsigned int	length;

	length = 0;
	if (number == 0)
		return (1);
	if (number < 0)
		length += 1;
	while (number != 0)
	{
		number /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	number;
	unsigned int	len;

	len = count_len(n);
	str = (char *) malloc (sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		number = -n;
	}
	else
		number = n;
	str[len] = '\0';
	while (number != 0)
	{
		str[len - 1] = (number % 10) + '0';
		number = number / 10;
		len--;
	}
	return (str);
}

