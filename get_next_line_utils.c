/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:46:11 by franaivo          #+#    #+#             */
/*   Updated: 2024/03/18 15:43:11 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

t_size_t	ft_strlen(const char *s)
{
	t_size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	chr;

	if (!s)
		return (0);
	chr = 0;
	chr = (char)c;
	while (*s)
	{
		if (*s == chr)
			return ((char *)s);
		s++;
	}
	if (*s == chr)
		return ((char *)s);
	return (0);
}

void	*ft_memcpy(void *dest, const void *src, t_size_t n)
{
	char		*ptr_dest;
	const char	*ptr_src = src;

	ptr_dest = dest;
	if (!dest && !src)
		return (NULL);
	while (n-- != 0)
	{
		*ptr_dest++ = *ptr_src++;
	}
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, t_size_t len)
{
	t_size_t	l_s;
	char		*str;

	l_s = 0;
	str = NULL;
	if (!*s)
		return (0);
	l_s = ft_strlen(s);
	if (l_s == 0 || start > l_s - 1)
		start = l_s;
	if (len > (l_s - start))
		len = l_s - start;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	ft_memcpy(str, (char *)(s + start), len);
	str[len] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	t_size_t	l_s1;
	t_size_t	l_s2;
	t_size_t	l_joined;
	char		*joined;

	l_s1 = ft_strlen(s1);
	l_s2 = ft_strlen(s2);
	l_joined = l_s1 + l_s2 + 1;
	joined = malloc(l_joined * sizeof(char));
	if (!joined)
		return (0);
	ft_memcpy(joined, s1, l_s1);
	ft_memcpy(joined + l_s1, s2, l_s2);
	joined[l_s2 + l_s1] = '\0';
	return (joined);
}
