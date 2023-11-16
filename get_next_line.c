/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:22:38 by nnourine          #+#    #+#             */
/*   Updated: 2023/11/16 16:43:07 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <stdio.h> //

static char	*ufree(void *extra, void *line)
{
	if (extra)
		ft_memset(extra, 0, (size_t)BUFFER_SIZE);
	if (line)
		free (line);
	return (NULL);
}


char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	extra[BUFFER_SIZE];
	char		*line;
	char		*temp;
	ssize_t		byt;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (ufree(extra, 0));
	line = ft_strjoin(0, extra);
	if (!line)
		return (ufree(extra, 0));
	ft_memset(extra, 0, (size_t)BUFFER_SIZE);
	byt = 1;
	while (ft_strchr(line, '\n') == 0 && byt)
	{
		byt = read(fd, buffer, BUFFER_SIZE);
		if (byt < 0)
			return (ufree(extra, line));
		buffer[byt] = '\0';
		temp = line;
		line = ft_strjoin(line, buffer);
		free(temp);
		if (!line)
			return (ufree(extra, 0));
	}
	if (byt)
	{
		if (*(ft_strchr(line, '\n') + 1) != '\0')
		{
			ft_memcpy(extra, (ft_strchr(line, '\n') + 1),
				ft_strlen(ft_strchr(line, '\n') + 1));
			*(ft_strchr(line, '\n') + 1) = '\0';
			temp = line;
			line = ft_strjoin(0, line);
			free(temp);
			if (!line)
				return (ufree(extra, 0));
		}
	}
	if (!line[0])
		return (ufree(0, line));
	return (line);
}
