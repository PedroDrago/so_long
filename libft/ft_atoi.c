/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 21:22:22 by pdrago            #+#    #+#             */
/*   Updated: 2023/11/01 12:19:57 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The ft_atoi() function converts the initial portion of the string pointed 
to by nptr to int. The string may begin with arbitrary amount of whitespace
determined by isspace(3), followed by a single optional '+' or '-' sign.
*/

int	ft_atoi(const char *nptr)
{
	int	number;
	int	sign;
	int	count;

	number = 0;
	sign = 1;
	count = 0;
	while ((nptr[count] >= 9 && nptr[count] <= 13) || (nptr[count] == 32))
		count++;
	if (nptr[count] == '-')
		sign = -1;
	if (nptr[count] == '-' || nptr[count] == '+')
		count++;
	while (nptr[count] >= '0' && nptr[count] <= '9')
		number = number * 10 + (nptr[count++] - '0');
	return (number * sign);
}
