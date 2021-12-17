/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbecki <hbecki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:08:22 by hbecki            #+#    #+#             */
/*   Updated: 2021/11/27 13:30:30 by hbecki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	1
# endif

char			*get_next_line(int fd);
void			*ft_calloc(size_t count, size_t size);
unsigned int	ft_strlen(const char *s);
int				ft_strrchr(const char *s, int c);
size_t			ft_strlcpy(char *dst, const char *src, int st, int maloc);
char			*ft_strjoin(char *s1, char *s2);
char			*get_next_line(int fd);
#endif
