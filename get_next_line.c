/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:22:38 by nnourine          #+#    #+#             */
/*   Updated: 2023/11/14 14:21:53 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	extra[BUFFER_SIZE];
	char		buffer[BUFFER_SIZE];
	char		*line;
	ssize_t		byt;

	if (read(fd, beffer, 0) < 0)
		return (NULL);
	byt = read(fd, beffer, BUFFER_SIZE);
	if (byt < 0)
		return (NULL);
	i = 0;
	line = ft_strdup (extra);
	while (byt > 0)
	{
		if (strchr(buffer, '\n') == 0)
		{
			line = strjoin(line, buffer);
			byt = read(fd, beffer, BUFFER_SIZE);
			if (byt < 0)
				return (NULL);
		}
		else
		{
			extra = strdup(strchr(buffer, '\n') + 1);
			*strchr(buffer, '\n') = '\0';
			line = strjoin(line, strdup(buffer));
			line = strjoin(line, "\n");
			return (line);
		}
	}
	line = strjoin(line, "\n");
	return (line);
}
