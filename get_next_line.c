/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:22:38 by nnourine          #+#    #+#             */
/*   Updated: 2023/11/16 15:24:12 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <stdio.h> //

static char	*ufree(void *extra, void *buffer)
{
	if (extra)
	{
		free (extra);
		extra = 0;
	}
	if (buffer)
		free (buffer);
	return (NULL);
}


char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	extra[BUFFER_SIZE + 1] = "";
	char		*line;
	char		*temp;
	ssize_t		byt;
	int 		i;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		i = 0;
		while (i < BUFFER_SIZE + 1)
		{
			extra[i] = '\0';
			i++;
		}
		return (NULL);
	}
	line = ft_strjoin(0, extra, 0);
	if (!line)
	{
		i = 0;
		while (i < BUFFER_SIZE + 1)
		{
			extra[i] = '\0';
			i++;
		}
		return (ufree(0, 0));
	}
	i = 0;
	while (i < BUFFER_SIZE + 1)
	{
		extra[i] = '\0';
		i++;
	}
	byt = 1;
	while (ft_strchr(line, '\n') == 0 && byt)
	{
		byt = read(fd, buffer, BUFFER_SIZE);
		if (byt < 0)
		{
			//printf( "extra : %s\n",extra);
			i = 0;
			while (i < BUFFER_SIZE + 1)
			{
				extra[i] = 0;
				i++;
			}
			//printf( "extra : %s\n",extra);
			i = 0;
			free(line);
			return (NULL);
		}
		buffer[byt] = '\0';
		temp = line;
		line = ft_strjoin(line, buffer, 0);
		free(temp);
		if (!line)
		{
			i = 0;
			while (i < BUFFER_SIZE + 1)
			{
				extra[i] = '\0';
				i++;
			}
			return (ufree(0, 0));
		}
	}
	if (byt)
	{
		if (*(ft_strchr(line, '\n') + 1) != '\0')
		{
			ft_memcpy(extra, (ft_strchr(line, '\n') + 1),
				ft_strlen(ft_strchr(line, '\n') + 1));
			*(ft_strchr(line, '\n') + 1) = '\0';
			temp = line;
			line = ft_strjoin(0, line, 0);
			free(temp);
			if (!line)
			{
				i = 0;
				while (i < BUFFER_SIZE + 1)
				{
					extra[i] = '\0';
					i++;
				}
				return (ufree(0, 0));
			}
		}
	}
	if (!line[0])
		return (ufree(0, line));
	return (line);
}
