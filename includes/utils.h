/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:53:29 by pdrago            #+#    #+#             */
/*   Updated: 2023/12/06 11:50:04 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "get_next_line.h"

# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif 

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif 

# ifndef UINT_MAX
#  define UINT_MAX 4294967295
# endif

# ifndef LONG_MAX
#  define LONG_MAX 9223372036854775807
# endif

# ifndef LONG_MIN
#  define LONG_MIN -9223372036854775808
# endif

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

int		ft_printf(const char *str, ...);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strchr(const char *s, int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif
