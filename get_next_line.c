/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:09:03 by franaivo          #+#    #+#             */
/*   Updated: 2024/04/04 11:57:13 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*catch(char **ptr1, char **ptr2, char *rtrn)
{
	free(*ptr1);
	free(*ptr2);
	*ptr1 = NULL;
	*ptr2 = NULL;
	return (rtrn);
}

int	feed_block(char **block, char *buffer, int fd)
{
	char	*new_block;
	int		r;

	new_block = NULL;
	r = 0;
	r = read(fd, buffer, BUFFER_SIZE);
	if (r < 0 || (r == 0 && !block))
	{
		return (r);
	}
	buffer[r] = '\0';
	if (!*block)
	{
		*block = ft_strjoin("", buffer);
	}
	else
	{
		new_block = ft_strjoin(*block, buffer);
		free(*block);
		*block = new_block;
	}
	return (r);
}

char	*extract_line(char **block)
{
	char	*new_block;
	char	*buffer;
	char	*newline_pos;

	new_block = NULL;
	buffer = NULL;
	if (!*block || !**block)
		return (catch (block, NULL, NULL));
	newline_pos = ft_strchr(*block, '\n');
	if (!newline_pos)
		newline_pos = ft_strchr(*block, '\0');
	else
		newline_pos++;
	new_block = ft_substr(*block, newline_pos - *block, -1);
	if (!new_block)
		return (0);
	buffer = ft_substr(*block, 0, newline_pos - *block);
	if (!buffer)
		return (catch (&new_block, NULL, NULL));
	free(*block);
	*block = new_block;
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*block;
	char		*buffer;
	int			r;

	buffer = NULL;
	r = -1;
	if (BUFFER_SIZE < 1 || fd < 0)
	{
		free(block);
		block = NULL;
		return (NULL);
	}
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (catch (&block, NULL, NULL));
	while ((!ft_strchr(block, '\n')) && r != 0)
	{
		r = feed_block(&block, buffer, fd);
		if (r < 0)
			return (catch (&buffer, &block, 0));
	}
	if (!block || (r == 0 && *block == '\0'))
		return (catch (&buffer, &block, 0));
	free(buffer);
	return (extract_line(&block));
}

