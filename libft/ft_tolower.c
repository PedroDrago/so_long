/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 21:42:31 by pdrago            #+#    #+#             */
/*   Updated: 2023/11/01 12:24:10 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
If c is an uppercase letter, ft_tolower() returns its lowercase equivalent.
*/

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
