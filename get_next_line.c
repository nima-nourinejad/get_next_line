/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:22:38 by nnourine          #+#    #+#             */
/*   Updated: 2023/11/16 17:57:18 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <stdio.h> //

static char	*ufree(void *extra, void *line)
{
	if (extra)
		ft_memset(extra, 0, (size_t)BUFFER_SIZE + 1);
	if (line)
		free (line);
	return (NULL);
}

static char	ft_extra(char *extra, char *line)
{
	ft_memcpy(extra, (ft_strchr(line, '\n') + 1),
		ft_strlen(ft_strchr(line, '\n') + 1));
	return ('\0');
}

static char	*line_check(char *line)
{
	if (!*line)
		return (ufree(0, line));
	return (line);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	extra[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		byt;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (ufree(extra, 0));
	line = ft_strjoin(0, extra);
	if (!line)
		return (ufree(extra, 0));
	byt = 1;
	while (ft_strchr(line, '\n') == 0 && byt)
	{
		byt = read(fd, buffer, BUFFER_SIZE);
		if (byt < 0)
			return (ufree(extra, line));
		buffer[byt] = '\0';
		line = ft_strjoin(line, buffer);
		if (!line)
			return (ufree(extra, 0));
	}
	if (ft_strchr(line, '\n') != 0 && *(ft_strchr(line, '\n') + 1) != '\0')
	{
		*(ft_strchr(line, '\n') + 1) = ft_extra(extra, line);
		line = ft_strjoin(line, 0);
		if (!line)
			return (ufree(extra, 0));
	}
	return (line_check(line));
}
