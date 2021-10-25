// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   get_next_line.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: hbecki <hbecki@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2021/10/22 12:33:29 by hbecki            #+#    #+#             */
// /*   Updated: 2021/10/25 15:00:31 by hbecki           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "get_next_line.h"

// unsigned int	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }


// int	ft_strrchr(const char *s, int c)
// {
// 	char	*pointer;
// 	char	*buf;
// 	int		j;

// 	buf = (char *)s;
// 	j = 0;
// 	while (j < ft_strlen(buf))
// 	{
// 		if (buf[j] == (char)c)	
// 			return (j);
// 		j++;
// 	}
// 	return (-1);
// }

// size_t	ft_strlcpy(char *dst, const char *src, int start, int maloc)
// {
// 	size_t		i;
// 	const char	*src_in;
// 	char		*dst_in;

// 	src_in = (const char *)src;
// 	dst_in = (char *)dst;
// 	i = 0;
// 	while ((src_in[i + start] != '\0') && ((src_in[i + start] != '\n') || maloc))
// 	{
// 		dst_in[i] = src_in[i + start];
// 		i++;
// 	}
// 	dst_in[i] = '\0';
// 	if (src_in[i + start] == '\0')
// 		return (-1);
// 	return (i);
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	char			*pointer_s;
// 	unsigned int	i;
// 	unsigned int	e;

// 	i = 0;
// 	if (s1 == NULL || s2 == NULL)
// 		return (NULL);
// 	e = (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
// 	pointer_s = (char *)malloc(e * sizeof(char));
// 	if (pointer_s == NULL)
// 		return (NULL);
// 	while (i < ft_strlen((char *)s1))
// 	{
// 		pointer_s[i] = (char)s1[i];
// 		i++;
// 	}
// 	while (i < ft_strlen((char *)s1) + ft_strlen((char *)s2))
// 	{
// 		pointer_s[i] = (char)s2[i - ft_strlen((char *)s1)];
// 		i++;
// 	}
// 	pointer_s[i] = '\0';
// 	free(s1);
// 	free(s2);
// 	return (pointer_s);
// }
// char	*ft_sewit(int *bq, char **str_tmp, char *str, char *buf, int t_n)
// {
// 	char *s;

// 	//printf("%s from sew1\n", buf);
// 	str = (char *)malloc((bq[1 - t_n] + 1) * sizeof(char));
	
// 	ft_strlcpy(str, buf, 0, 0);
// 	//printf("%s from sew2\n", *str_tmp);
// 	str[bq[1 - t_n] + 1] = '\0';
// 	if (*str_tmp != NULL) //sew up if needed
// 	{
// 		s = ft_strjoin(*str_tmp, str);
// 		str = s;
// 		if (t_n == 0)
// 			*str_tmp = str;
// 	}
// 	if (t_n == 1)
// 	{
// 		str[ft_strlen(str)] = '\n';
// 		*str_tmp = NULL;
// 		return (str);
// 	}
// 	else if (*str_tmp == NULL)
// 		*str_tmp = str;
// 	return (*str_tmp);

// }
// char *evth_exc_read(int	(*bq)[2], char **keys, char **str_tmp, char **buf, int t_r)
// {
// 	char	*str;
// 	char	*s;

// 	str = NULL;
// 	//printf("%s from buf1\n", *buf);
// 	(*bq)[0] = ft_strrchr(*buf, '\n');
// 	//printf("%d from buf2\n", (*bq)[0]);
// 	// printf("%d neeeeee\n", (*bq)[0]);
	
// 	if ((*bq)[0] != -1) //if there is a \n
// 	{
// 		str = ft_sewit(*bq, str_tmp, str, *buf, 1);
		
// 		if ((*bq)[1] + 1 - ((*bq)[0] + 1) > 0) //if anything left in the buf
// 		{
// 			if (t_r == 1)
// 			{
// 				*keys = (char *)malloc(((*bq)[1] + 1 - ((*bq)[0] + 1)) * sizeof(char));
// 				ft_strlcpy(*keys, *buf, (*bq)[0] + 1, 1);
// 				//printf("%d from buf\n", (*bq)[0]);
// 				// free(*buf);
// 				// printf("%d from extg_re\n", ((*bq)[1] + 1 - ((*bq)[0] + 1)));
// 			}
// 			else
// 			{
// 				s = (char *)malloc(((*bq)[1] + 1 - ((*bq)[0] + 1)) * sizeof(char));
// 				ft_strlcpy(s, *buf, (*bq)[0] + 1, 1);
// 				*buf = s;
// 			}
// 		}
		
// 		// printf("%s from extg_re1\n", str);
// 		return (str);
// 	}
// 	else{

// 		//printf("%s from buf3\n", *buf);
// 		*str_tmp = ft_sewit(*bq, str_tmp, str, *buf, 0);
// 		//printf("%s from extg_re2\n", *str_tmp);
// 		return(NULL);//remove
// 	}
// 	free(*buf);
// }
// char	*final_circle(int fd, char **keys, int if_residue)
// {
// 	char		*buf;
// 	char		*str;
// 	int			bq[2];
// 	char		*str_tmp;
// 	char		*s;
		
	
// 	str = NULL;
// 	str_tmp = NULL;
// 	//printf("%s    from final\n", *keys);
// 	if (if_residue == 0)
// 	{
// 		str = NULL;
// 		str = evth_exc_read(&bq, NULL, &str_tmp, keys, 0);
// 	}
// 	//printf("%s    from final\n", *keys);
// 	if (str != NULL)
// 		return (str);
// 	else 
// 	{
		
// 		while (1)
// 		{
// 			buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
// 			bq[1] = read(fd, buf, BUFFER_SIZE);
// 			if (bq[1] < 1)
// 			{
// 				printf("%s\n", "the end");
// 				return (NULL);
// 			}
// 			buf[bq[1]] = '\0';
// 			str = NULL;
// 			str = evth_exc_read(&bq, keys, &str_tmp, &buf, 1);
// 			if (str != NULL)
// 				return (str);
// 		}
// 	}
// }
// char	*get_next_line(int fd)
// {
// 	static char	*keys[1024];
// 	int			bq[2];
// 	char		*buf;
// 	char		*str;
// 	char		*str_tmp;
// 	char		*s;
	
// 	str = NULL;
// 	str_tmp = NULL;
// 	//printf("%s  key\n", str_tmp);
// 	if (keys[fd] == NULL)
// 	{
// 		return (final_circle(fd, &keys[fd], 1));
// 		// while (1)
// 		// {
// 		// 	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
// 		// 	bq[1] = read(fd, buf, BUFFER_SIZE);
// 		// 	if (bq[1] < 1)
// 		// 	{
// 		// 		printf("%s\n", "the end111");
// 		// 		return (NULL);
// 		// 	}
// 		// 	buf[bq[1]] = '\0';
// 		// 	str = NULL;
// 		// 	str = evth_exc_read(&bq, &keys[fd], &str_tmp, &buf, 1);
// 		// 	if (str != NULL)
// 		// 		return (str);
// 		// }

// 	}
// 	else
// 	{
// 	// 	str = NULL;
// 	// 	//printf("%s branch 2\n", keys[fd]);
// 	// 	str = evth_exc_read(&bq, NULL, &str_tmp, &keys[fd], 0);
		

// 	// 	if (str != NULL)
// 	// 		return (str);
// 	// 	else 
// 	// 	{
// 	// 		while (1)
// 	// 		{
// 	// 			buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	// 			bq[1] = read(fd, buf, BUFFER_SIZE);
// 	// 			if (bq[1] < 1)
// 	// 			{
// 	// 				printf("%s\n", "the end");
// 	// 				return (NULL);
// 	// 			}
// 	// 			buf[bq[1]] = '\0';
// 	// 			str = NULL;
// 	// 			str = evth_exc_read(&bq, &keys[fd], &str_tmp, &buf, 1);
// 	// 			if (str != NULL)
// 	// 				return (str);
// 	// 		}
// 	// 	}
// 		return (final_circle(fd, &keys[fd], 0));
		
// 	}

// }


// int main(void)
// {
// 	char	*s;
// 	int		fd;

// 	fd = open("file.txt", O_RDONLY);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	//free(s);
// }