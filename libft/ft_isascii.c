/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:56:50 by pdrago            #+#    #+#             */
/*   Updated: 2023/11/01 12:21:01 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
checks whether c is a 7-bit unsigned char value 
that fits into the ASCII character set.
*/

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
