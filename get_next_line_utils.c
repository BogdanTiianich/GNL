/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbecki <hbecki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:46:03 by hbecki            #+#    #+#             */
/*   Updated: 2021/11/08 18:12:27 by hbecki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*pointer;
	size_t	i;

	i = 0;
	pointer = (char *)malloc(count * size);
	if (pointer == NULL)
		return (NULL);
	while (i < count * size)
	{
		pointer[i] = '\0';
		i++;
	}
	return ((void *)pointer);
}

unsigned int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strrchr(const char *s, int c)
{
	char				*buf;
	unsigned int		j;

	buf = (char *)s;
	j = 0;
	while (j < ft_strlen(buf))
	{
		if (buf[j] == (char)c)
			return (j);
		j++;
	}
	return (-1);
}

size_t	ft_strlcpy(char *dst, const char *src, int start, int maloc)
{
	size_t		i;
	const char	*src_in;
	char		*dst_in;

	src_in = (const char *)src;
	dst_in = (char *)dst;
	i = 0;
	while ((src_in[i + start] != '\0') && ((src_in[i + start] != '\n') || maloc))
	{
		dst_in[i] = src_in[i + start];
		i++;
	}
	dst_in[i] = '\0';
	if (src_in[i + start] == '\0')
		return (-1);
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*pointer_s;
	unsigned int	e[3];

	e[2] = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	e[0] = ft_strlen((char *)s1);
	e[1] = ft_strlen((char *)s2);
	pointer_s = (char *)ft_calloc(e[0] + e[1] + 2, sizeof(char));
	if (pointer_s == NULL)
		return (NULL);
	while (e[2] < e[0])
	{
		pointer_s[e[2]] = (char)s1[e[2]];
		e[2]++;
	}
	while (e[2] < e[0] + e[1])
	{
		pointer_s[e[2]] = (char)s2[e[2] - e[0]];
		e[2]++;
	}
	pointer_s[e[2]] = '\0';
	free(s1);
	free(s2);
	return (pointer_s);
}
