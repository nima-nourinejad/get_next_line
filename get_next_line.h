/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:36:16 by nnourine          #+#    #+#             */
/*   Updated: 2023/11/16 16:42:35 by nnourine         ###   ########.fr       */
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
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, char c);
void	*ft_memset(void *ptr, int val, size_t size);

#endif // GET_NEXT_LINE_H