/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: username <your@mail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:08:18 by username          #+#    #+#             */
/*   Updated: 2024/03/18 15:26:30 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif // !BUFFER_SIZE

# include <stdlib.h>

typedef unsigned long	t_size_t;

t_size_t				ft_strlen(const char *s);
void					*ft_memcpy(void *dest, const void *src, t_size_t n);
char					*ft_strchr(const char *s, int c);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_substr(char const *s, unsigned int start,
							t_size_t len);
char					*get_next_line(int fd);
#endif // GET_NEXT_LINE_H
