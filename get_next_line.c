/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbecki <hbecki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 12:33:29 by hbecki            #+#    #+#             */
/*   Updated: 2021/10/25 20:26:36 by hbecki           ###   ########.fr       */
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
	unsigned int	i;
	unsigned int	e;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	e = (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 2);//chnge to +1
	//printf("%d maloc strjoin\n", (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1));
	pointer_s = (char *)ft_calloc(e, sizeof(char));
	if (pointer_s == NULL)
		return (NULL);
	while (i < ft_strlen((char *)s1))
	{
		pointer_s[i] = (char)s1[i];
		i++;
	}
	while (i < ft_strlen((char *)s1) + ft_strlen((char *)s2))
	{
		pointer_s[i] = (char)s2[i - ft_strlen((char *)s1)];
		i++;
	}
	//printf("%d  i  %c   s\n",  i, pointer_s[i - 1]);
	pointer_s[i] = '\0';
	free(s1);
	free(s2);
	return (pointer_s);
}

char	*ft_sewit(int *bq, char **str_tmp, char *str, char *buf, int t_n)
{
	char *s;

	////printf("%s from sew1\n", buf);
	str = (char *)ft_calloc((bq[1 - t_n] + 1), sizeof(char));
	if (str == NULL)
		return (NULL);
	
	ft_strlcpy(str, buf, 0, 0);
	//printf("%s str from sew \n", str);
	str[bq[1 - t_n] + 1] = '\0';
	if (*str_tmp != NULL) //sew up if needed
	{
		s = ft_strjoin(*str_tmp, str);
		str = s;
		if (t_n == 0)
			*str_tmp = str;
	}
	if (t_n == 1)
	{
		//printf("%d maloc str\n", ft_strlen(str));
		str[ft_strlen(str)] = '\n';
		str[ft_strlen(str) + 1] = '\0';//delete
		
		*str_tmp = NULL;
		return (str);
	}
	else if (*str_tmp == NULL)
		*str_tmp = str;
	return (*str_tmp);

}
char *evth_exc_read(int	(*bq)[2], char **keys, char **str_tmp, char **buf, int t_r)
{
	char	*str;
	char	*s;

	str = NULL;

	(*bq)[0] = ft_strrchr(*buf, '\n');

	if ((*bq)[0] != -1) //if there is a \n
	{
		printf("%s 1\n", *buf);
		str = ft_sewit(*bq, str_tmp, str, *buf, 1);
		
		if ((*bq)[1] + 1 - ((*bq)[0] + 1) > 1 && ft_strlen(*buf) > 1) //if anything left in the buf
		{
			
			if (t_r == 1)
			{
				printf("%s 2\n", "in");
				*keys = (char *)ft_calloc(((*bq)[1] + 1 - ((*bq)[0] + 1)), sizeof(char));
				if (*keys == NULL)
					return (NULL);
				ft_strlcpy(*keys, *buf, (*bq)[0] + 1, 1);
				// printf("%d free buf1\n", ((*bq)[1]  - ((*bq)[0])));
				// printf("%d free buf1 %d\n", (*bq)[0], (*bq)[1]);
			}
			else
			{
				s = (char *)ft_calloc(((*bq)[1] + 1 - ((*bq)[0] + 1)), sizeof(char));
				if (s == NULL)
					return (NULL);
				ft_strlcpy(s, *buf, (*bq)[0] + 1, 1);
				printf("%d 3\n", (*bq)[0]);
				free(*buf);
				*buf = s;
				return (str);
				//printf("%d free buf2\n", t_r);
			}
		}
	}
	else
	{	//printf("%s no///n\n", *buf);
		*str_tmp = ft_sewit(*bq, str_tmp, str, *buf, 0);
	}
	if (*buf != NULL)
	{
		printf("%d 3dfsdfsdfsdn", (*bq)[0]);
		free(*buf);
		*buf = NULL;
	}
	
	return(str);
}
char	*final_circle(int fd, char **keys, int if_residue)
{
	char		*buf;
	char		*str;
	int			bq[2];
	char		*str_tmp;
	
	str = NULL;
	str_tmp = NULL;

	if (if_residue == 0)
	{
		printf("%s    from final\n", *keys);
		str = evth_exc_read(&bq, NULL, &str_tmp, keys, 0);
	}
	//printf("%s    from final\n", *keys);
	if (str != NULL)
	{
		//printf("\n%s    from final\n", str);
		return (str);
	}
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
				if (*keys != NULL)
				{
					free(*keys);
					*keys = NULL;
				}
				if (buf != NULL)
				{
					free(buf);
					buf = NULL;
				}
				return (str_tmp);
			}
			buf[bq[1]] = '\0';
			
			str = evth_exc_read(&bq, keys, &str_tmp, &buf, 1);
			if (str != NULL)
			{
				return (str);
			}
		}
	}
}
char	*get_next_line(int fd)
{
	static char	*keys[1024];
	char *str;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (NULL);
	if (keys[fd] == NULL)
	{
		str = final_circle(fd, &keys[fd], 1);
		// if (keys[fd] != NULL)
		// 	free(keys[fd]);
		return (str);
	}
	else
	{
		str = final_circle(fd, &keys[fd], 0);
		// if (keys[fd] != NULL)
		// 	free(keys[fd]);
		return (str);
	}

}


int main(void)
{
	char	*s;
	char	*s1;
	int		fd;

	fd = open("file.txt", O_RDONLY);
	// s = get_next_line(fd);
	// while (s != NULL)
	// {
	// 	printf("%s", s);
	// 	free(s);
	// 	s = get_next_line(fd);
		
	// }
	s = get_next_line(fd);
	printf("1  %s", s);
	s = get_next_line(fd);
	printf("2  %s", s);
	s = get_next_line(fd);
	printf("3  %s", s);
	s = get_next_line(fd);
	printf("4  %s", s);
	s = get_next_line(fd);
	printf("5  %s", s);
	s = get_next_line(fd);
	printf("6  %s", s);
	// s = get_next_line(fd);
	// printf("7%s", s);

}