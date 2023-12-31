/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:24:17 by nnourine          #+#    #+#             */
/*   Updated: 2023/11/16 16:42:19 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	if (*s == '\0')
		return (0);
	else
	{
		while (*s != '\0')
		{
			++s;
			++len;
		}
		return (len);
	}
}

char	*ft_memcpy(char *d, char *s, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (d);
	while (i < n)
	{
		*(d + i) = *(s + i);
		i++;
	}
	return (d);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*d;
	size_t	l1;
	size_t	l2;

	l1 = ft_strlen (s1);
	l2 = ft_strlen (s2);
	d = malloc((l1 + l2 + 1) * sizeof (char));
	if (d == 0)
		return (0);
	ft_memcpy(d, s1, l1);
	ft_memcpy(d + l1, s2, l2);
	d[l1 + l2] = '\0';
	return (d);
}

char	*ft_strchr(char *s, char c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (c == 0)
		return ((char *)(s + ((int)ft_strlen(s))));
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}

void	*ft_memset(void *ptr, int val, size_t size)
{
	size_t			i;
	unsigned char	v;
	unsigned char	*p;

	i = 0;
	v = (unsigned char) val;
	p = (unsigned char *) ptr;
	while (i < size)
	{
		*(p + i) = v;
		i++;
	}
	return (ptr);
}
