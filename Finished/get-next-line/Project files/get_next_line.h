/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpenaran <gpenaran@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 18:25:20 by gpenaran          #+#    #+#             */
/*   Updated: 2020/07/04 14:53:04 by gpenaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
void		*ft_memmove(void *dst, const void *src, size_t len);
char		*ft_substr(char const *s, int start, int len);
int			get_next_line(int fd, char **line);
char		*join_and_free(char *s1, char *s2);
int			find_index(const char *s, int c);
int			get_line(char *str, char **line, int i);

#endif
