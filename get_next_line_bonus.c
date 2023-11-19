/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:22:38 by nnourine          #+#    #+#             */
/*   Updated: 2023/11/19 12:29:22 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*zero_free(void *extra, void *line)
{
	if (extra)
		ft_memset(extra, 0, (size_t)BUFFER_SIZE);
	if (line)
		free (line);
	return (NULL);
}

static char	*line_maker(int fd, char *extra)
{
	ssize_t	byt;
	char	*temp;
	char	*line;
	char	buffer[BUFFER_SIZE + 1];

	byt = 1;
	line = ft_strjoin(0, extra);
	if (!line)
		return (zero_free(extra, 0));
	zero_free(extra, 0);
	while (ft_strchr(line, '\n') == 0 && byt)
	{
		byt = read(fd, buffer, BUFFER_SIZE);
		if (byt < 0)
			return (zero_free(extra, line));
		buffer[byt] = '\0';
		temp = line;
		line = ft_strjoin(line, buffer);
		free(temp);
		if (!line)
			return (zero_free(extra, 0));
	}
	return (line);
}

static char	*extra_remover(char *line, char *extra)
{
	char		*temp;

	if (ft_strchr(line, '\n') != 0 && *(ft_strchr(line, '\n') + 1) != '\0')
	{
		ft_memcpy(extra, (ft_strchr(line, '\n') + 1),
			ft_strlen(ft_strchr(line, '\n') + 1));
		*(ft_strchr(line, '\n') + 1) = '\0';
		temp = line;
		line = ft_strjoin(0, line);
		free(temp);
		if (!line)
			return (zero_free(extra, 0));
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	extra[MAX_FD][BUFFER_SIZE];
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0 || fd > MAX_FD - 1)
		return (NULL);
	if (read(fd, 0, 0) < 0)
		return (zero_free(extra[fd], 0));
	line = line_maker(fd, extra[fd]);
	if (!line)
		return (zero_free(extra[fd], 0));
	line = extra_remover(line, extra[fd]);
	if (!line)
		return (zero_free(extra[fd], 0));
	if (!*line)
		return (zero_free(0, line));
	return (line);
}
