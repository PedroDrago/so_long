/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:56:50 by pdrago            #+#    #+#             */
/*   Updated: 2023/11/01 12:20:47 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
checks for any printable character including space.
*/

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
