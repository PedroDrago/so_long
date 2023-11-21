/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:46:44 by pdrago            #+#    #+#             */
/*   Updated: 2023/11/16 18:42:43 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_resolve_print(char c, va_list args)
{
	if (c == 'c')
		return (ft_retputchar(va_arg(args, int)));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr_base(va_arg(args, int), 10, 1, "0123456789"));
	else if (c == 's')
		return (ft_retputstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putpointer(va_arg(args, void *)));
	else if (c == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int),
				10, 0, "0123456789"));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(args, int), 16, 0, "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(args, int), 16, 0, "0123456789ABCDEF"));
	else if (c == '%')
		return (ft_retputchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		index;
	int		total_count;
	va_list	args;

	index = -1;
	total_count = 0;
	va_start(args, str);
	while (str[++index])
	{
		if (str[index] == '%')
		{
			index++;
			total_count += ft_resolve_print(str[index], args);
		}
		else
			total_count += ft_retputchar(str[index]);
	}
	va_end(args);
	return (total_count);
}
