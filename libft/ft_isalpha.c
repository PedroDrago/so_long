/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:56:50 by pdrago            #+#    #+#             */
/*   Updated: 2023/11/01 12:21:09 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Checks  for  an  alphabetic  character, it is 
equivalent to (ft_isupper(c) || ft_islower(c)).
*/

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
