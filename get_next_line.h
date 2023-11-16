/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:36:16 by nnourine          #+#    #+#             */
/*   Updated: 2023/11/15 17:24:27 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 80
# endif // BUFFER_SIZE

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_memcpy(char *d, char *s, size_t n);
char	*ft_strjoin(char *s1, char *s2, int triger);
char	*ft_strchr(char *s, char c);

#endif // GET_NEXT_LINE_H