/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbecki <hbecki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:33:29 by hbecki            #+#    #+#             */
/*   Updated: 2021/11/27 13:26:03 by hbecki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_sewit(int *x, char **str_tmp, char *str, char *buf)
{
	char	*s;

	str = (char *)ft_calloc((x[1 - x[4]] + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, buf, 0, 0);
	str[x[1 - x[4]] + 1] = '\0';
	if (*str_tmp != NULL)
	{
		s = ft_strjoin(*str_tmp, str);
		str = s;
		if (x[4] == 0)
			*str_tmp = str;
	}
	if (x[4] == 1)
	{
		str[ft_strlen(str)] = '\n';
		*str_tmp = NULL;
		return (str);
	}
	else if (*str_tmp == NULL && ft_strlen(str) > 0)
		*str_tmp = str;
	if (*str_tmp == NULL && ft_strlen(str) == 0)
		free(str);
	return (*str_tmp);
}

static char	*eer_helper(int *x[6], char **keys, char **buf)
{
	char	*s;

	if ((*x)[1] - (*x)[0] > 1 && ft_strlen(*buf) > 1)
	{	
		if ((*x)[3] == 1)
		{
			*keys = (char *)ft_calloc(((*x)[1] - (*x)[0]), sizeof(char));
			if (*keys == NULL)
				return (NULL);
			ft_strlcpy(*keys, *buf, (*x)[0] + 1, 1);
		}
		else
		{
			s = (char *)ft_calloc(((*x)[1] - (*x)[0]), sizeof(char));
			if (s == NULL)
				return (NULL);
			ft_strlcpy(s, *buf, (*x)[0] + 1, 1);
			free(*buf);
			*buf = s;
			(*x)[3] = 20 + (*x)[3];
		}
	}
	(*x)[3] = 10 + (*x)[3];
	return (NULL);
}

static char	*evth_ex_rd(int *x[6], char **keys, char **str_tmp, char **buf)
{
	char	*str;
	char	*s;

	str = NULL;
	(*x)[0] = ft_strrchr(*buf, '\n');
	(*x)[4] = 0;
	if ((*x)[0] != -1)
	{
		(*x)[4] = 1;
		str = ft_sewit(*x, str_tmp, str, *buf);
		s = eer_helper(x, keys, buf);
		if (((*x)[3] != 10 && (*x)[3] != 11) && (*x)[3] >= 20)
			return (str);
		else if ((*x)[3] != 10 && (*x)[3] != 11)
			return (s);
		(*x)[3] = (*x)[3] % 10;
	}
	else
		*str_tmp = ft_sewit(*x, str_tmp, str, *buf);
	if (*buf != NULL)
	{
		free(*buf);
		*buf = NULL;
	}
	return (str);
}

static char	*final_circle(int x[6], char **keys, char *str, char *str_tmp)
{
	char		*buf;

	if (x[5] == 0)
		str = evth_ex_rd((&x), NULL, &str_tmp, keys);
	if (str != NULL)
		return (str);
	else
	{
		while (1)
		{
			x[3] = 1;
			buf = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
			if (buf == NULL)
				return (NULL);
			x[1] = read(x[2], buf, BUFFER_SIZE);
			if (x[1] < 1)
			{
				free(buf);
				return (str_tmp);
			}
			str = evth_ex_rd(&x, keys, &str_tmp, &buf);
			if (str != NULL)
				return (str);
		}
	}
}

char	*get_next_line(int fd)
{
	static char	*keys[1024];
	char		*str;
	int			x[6];

	x[3] = 0;
	x[2] = fd;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (NULL);
	if (keys[fd] == NULL)
	{
		x[5] = 1;
		str = final_circle(x, &keys[fd], NULL, NULL);
		return (str);
	}
	else
	{
		x[5] = 0;
		str = final_circle(x, &keys[fd], NULL, NULL);
		return (str);
	}
}
