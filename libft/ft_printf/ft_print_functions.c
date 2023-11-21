/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 05:34:20 by pdrago            #+#    #+#             */
/*   Updated: 2023/11/16 18:40:53 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_retputchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_retputstr(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (ft_retputstr("(null)"));
	while (str[count])
		count++;
	write(1, str, count);
	return (count);
}

int	ft_putnbr_base(int n, int base, int sign, char charset[])
{
	unsigned int	number;
	int				count;
	char			buff[16];

	count = 0;
	if (n == 0)
		return (ft_retputchar('0'));
	if (sign && n < 0)
		number = -n;
	else
		number = n;
	while (number != 0)
	{
		buff[count++] = charset[number % base];
		number /= base;
	}
	if (sign && n < 0)
		buff[count++] = '-';
	while (--count >= 0)
		number += ft_retputchar(buff[count]);
	return (number);
}

int	ft_putpointer(void *ptr)
{
	unsigned long int	number;
	int					count;
	char				*charset;
	char				buff[16];
	unsigned long		ptr2;

	ptr2 = (unsigned long) ptr;
	if (ptr2 == (unsigned long) NULL)
		return (ft_retputstr("(nil)"));
	count = 0;
	charset = "0123456789abcdef";
	while (ptr2 != 0)
	{
		buff[count++] = charset[(unsigned long) ptr2 % 16];
		ptr2 /= 16;
	}
	number = count--;
	ft_retputstr("0x");
	while (count >= 0)
		ft_retputchar(buff[count--]);
	return (number + 2);
}
