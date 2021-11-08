/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbecki <hbecki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:33:29 by hbecki            #+#    #+#             */
/*   Updated: 2021/11/08 18:38:54 by hbecki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <time.h>

char	*ft_sewit(int *bq, char **str_tmp, char *str, char *buf, int t_n)//too many
{
	char	*s;

	str = (char *)ft_calloc((bq[1 - t_n] + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, buf, 0, 0);
	str[bq[1 - t_n] + 1] = '\0';
	if (*str_tmp != NULL)
	{
		s = ft_strjoin(*str_tmp, str);
		str = s;
		if (t_n == 0)
			*str_tmp = str;
	}
	if (t_n == 1)
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

char	*eer_helper(int (*bq)[2], char **keys, char **buf, int *t_r)
{
	char	*s;

	if ((*bq)[1] - (*bq)[0] > 1 && ft_strlen(*buf) > 1)
	{	
		if (*t_r == 1)
		{
			*keys = (char *)ft_calloc(((*bq)[1] - (*bq)[0]), sizeof(char));
			if (*keys == NULL)
				return (NULL);
			ft_strlcpy(*keys, *buf, (*bq)[0] + 1, 1);
		}
		else
		{
			s = (char *)ft_calloc(((*bq)[1] - (*bq)[0]), sizeof(char));
			if (s == NULL)
				return (NULL);
			ft_strlcpy(s, *buf, (*bq)[0] + 1, 1);
			free(*buf);
			*buf = s;
			*t_r = 20 + *t_r;
		}
	}
	*t_r = 10 + *t_r;
	return (NULL);
}

char	*evth_exc_read(int (*bq)[2], char **keys, char **str_tmp, char **buf, int t_r)//too many
{
	char	*str;
	char	*s;

	str = NULL;
	(*bq)[0] = ft_strrchr(*buf, '\n');
	if ((*bq)[0] != -1)
	{
		str = ft_sewit(*bq, str_tmp, str, *buf, 1);
		s = eer_helper(bq, keys, buf, &t_r);
		if ((t_r != 10 && t_r != 11) && t_r >= 20)
			return (str);
		else if (t_r != 10 && t_r != 11)
			return (s);
		t_r = t_r % 10;
	}
	else
		*str_tmp = ft_sewit(*bq, str_tmp, str, *buf, 0);
	if (*buf != NULL)
	{
		free(*buf);
		*buf = NULL;
	}
	return (str);
}

char	*final_circle(int fd, char **keys, int if_residue, char *str, char *str_tmp)//too many
{
	char		*buf;
	int			bq[2];

	if (if_residue == 0)
		str = evth_exc_read(&bq, NULL, &str_tmp, keys, 0);
	if (str != NULL)
		return (str);
	else
	{
		while (1)
		{
			buf = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
			if (buf == NULL)
				return (NULL);
			bq[1] = read(fd, buf, BUFFER_SIZE);
			if (bq[1] < 1)
			{
				free(buf);
				return (str_tmp);
			}
			str = evth_exc_read(&bq, keys, &str_tmp, &buf, 1);
			if (str != NULL)
				return (str);
		}
	}
}

char	*get_next_line(int fd)
{
	static char	*keys[1024];
	char		*str;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (NULL);
	if (keys[fd] == NULL)
	{
		str = final_circle(fd, &keys[fd], 1, NULL, NULL);
		return (str);
	}
	else
	{
		str = final_circle(fd, &keys[fd], 0, NULL, NULL);
		return (str);
	}
}


// int main(void)
// {
// 	char	*s;
// 	char	*s1;
// 	int		fd;

	
// 	fd = open("file.txt", O_RDONLY);
// 	s = get_next_line(fd);
	
// 	while (s != NULL)
// 	{
// 		printf("%s", s);
// 		free(s);
// 		s = get_next_line(fd);
// 	}
	
// 	// s = get_next_line(fd);
// 	// printf("1  %s", s);
// 	// free(s);
// 	// s = get_next_line(fd);
// 	// printf("2  %s", s);
// 	// free(s);
// 	// s = get_next_line(fd);
// 	// printf("3  %s", s);
// 	// free(s);
// 	// s = get_next_line(fd);
// 	// printf("4  %s", s);
// 	// free(s);
// 	// s = get_next_line(fd);
// 	// printf("5  %s", s);
// 	// free(s);
// 	// s = get_next_line(fd);
// 	// printf("6  %s", s);
// 	// free(s);
// 	// s = get_next_line(fd);
// 	// printf("7%s", s);

// }