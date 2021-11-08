/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbecki <hbecki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:08:22 by hbecki            #+#    #+#             */
/*   Updated: 2021/11/08 18:37:31 by hbecki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
# define BUFFER_SIZE	1
# endif

char			*get_next_line(int fd);
void			*ft_calloc(size_t count, size_t size);
unsigned int	ft_strlen(const char *s);
int				ft_strrchr(const char *s, int c);
size_t			ft_strlcpy(char *dst, const char *src, int start, int maloc);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_sewit(int *bq, char **str_tmp, char *str, char *buf, int t_n);
char 			*evth_exc_read(int	(*bq)[2], char **keys, char **str_tmp, char **buf, int t_r);
char			*final_circle(int fd, char **keys, int if_residue, char *str, char *str_tmp);
char			*get_next_line(int fd);
#endif