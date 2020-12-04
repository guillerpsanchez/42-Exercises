/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcft.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpenaran <gpenaran@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:22:21 by gpenaran          #+#    #+#             */
/*   Updated: 2020/12/03 11:44:09 by gpenaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCFT_H
# define LIBCFT_H

# include <unistd.h>
# include <stdlib.h>

int			ft_isdigit(int c);
int			ft_tolower(int c);
char		*ft_itoa(int n);
int			ft_putchar(char c);
char		*ft_str_tolower(char *str);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *str);
int			ft_putstr(char *str, int precision);
char		*ft_u_itoa(unsigned int n);
char		*ft_utl_base(unsigned long long number, int base);

#endif
