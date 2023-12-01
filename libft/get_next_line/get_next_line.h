/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdrago <pdrago@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:46:13 by pdrago            #+#    #+#             */
/*   Updated: 2023/11/16 23:12:14 by pdrago           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h> 

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

int		gnl_len(char *str);
int		has_break_line(const char *s);
char	*ft_joinfree(char *s1, char *s2);
char	*get_next_line(int fd);
char	*read_line(int fd);
char	*dup_post_n(char *buffer);
char	*dup_pre_n(char *buffer);

#endif
