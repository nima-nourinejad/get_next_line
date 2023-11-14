/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:24:17 by nnourine          #+#    #+#             */
/*   Updated: 2023/11/14 14:03:09 by nnourine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
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

char	*ft_strdup(const char *s)
{
	size_t	l;
	char	*d;

	l = ft_strlen(s);
	d = malloc((l + 1) * sizeof (char));
	if (d == 0)
		return (0);
	ft_memcpy (d, s, l + 1);
	return (d);
}

char	*ft_strchr(const char *s, int c1)
{
	int		i;
	char	c;

	i = 0;
	c = (char) c1;
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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *)dst;
	s = (char *)src;
	if (n == 0 || dst == src)
		return (dst);
	while (i < n)
	{
		*(d + i) = *(s + i);
		i++;
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;
	size_t	l1;
	size_t	l2;

	if (s1 == 0 && s2 == 0)
		return (ft_strdup(""));
	if (s1 == 0)
		return (ft_strdup(s2));
	if (s2 == 0)
		return (ft_strdup(s1));
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
