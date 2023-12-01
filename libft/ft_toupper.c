/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 21:42:31 by pdrago            #+#    #+#             */
/*   Updated: 2023/11/01 12:24:06 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
If  c  is  a  lowercase  letter, ft_toupper() returns its uppercase equivalent.
*/

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
