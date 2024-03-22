/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:09:03 by franaivo          #+#    #+#             */
/*   Updated: 2024/03/22 12:19:12 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	feed_block(char **block, char *buffer, int fd)
{
	char	*new_block;
	int		r;

	new_block = NULL;
	r = 0;
	r = read(fd, buffer, BUFFER_SIZE);
	if (r < 0 || (r == 0 && !block))
	{
		free(buffer);
		free(block);
		return (r);
	}
	buffer[r] = '\0';
	if (!*block)
		*block = ft_strjoin(buffer, "");
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
		return (0);
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
	{
		free(new_block);
		return (0);
	}
	free(*block);
	*block = new_block;
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*block = NULL;
	char		*buffer;
	int			r;

	buffer = NULL;
	r = -1;
	if (BUFFER_SIZE < 1 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(block);
		return (0);
	}
	while ((!ft_strchr(block, '\n')) && r != 0)
	{
		r = feed_block(&block, buffer, fd);
		if (r < 0)
			return (NULL);
	}
	if (!block)
		return (0);
	free(buffer);
	return (extract_line(&block));
}
/*
int	main(void)
{
	int	fd;

	fd = 0;
	fd = open("big_line_with_nl", O_RDONLY);
  printf("%s" , get_next_line(fd));
  printf("%s" , get_next_line(fd));
  printf("%s" , get_next_line(fd));
  printf("%s" , get_next_line(fd));
  printf("%s" , get_next_line(fd));
  printf("%s" , get_next_line(fd));
  printf("%s" , get_next_line(fd));
  printf("%s" , get_next_line(fd));
  printf("%s" , get_next_line(fd));
  printf("%s" , get_next_line(fd));
  printf("%s" , get_next_line(fd));
  printf("%s" , get_next_line(fd));
  return (0);
}
*/
