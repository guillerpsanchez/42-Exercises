/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpenaran <gpenaran@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 15:18:59 by gpenaran          #+#    #+#             */
/*   Updated: 2020/12/03 12:14:39 by gpenaran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libcft/libcft.h"

typedef struct	s_flags
{
	int		asterisk;
	int		width;
	int		zero;
	int		minus;
	int		type;
	int		dot;
}				t_flags;

int				ft_isflag(int c);
int				ft_checkconversion(int c);
int				ft_char(char c, t_flags flags);
t_flags			ft_minus_flag(t_flags flags);
t_flags			ft_digit_flag(char c, t_flags flags);
t_flags			ft_width_flag(va_list args, t_flags flags);
int				ft_dot_flag(const char *str, int init,
t_flags *flags, va_list args);
int				ft_hexa(unsigned int number,
int lowercase, t_flags flags);
int				ft_int(int i, t_flags flags);
int				ft_percent(t_flags flags);
int				ft_pointer(unsigned long long num, t_flags flags);
int				ft_string(char *str, t_flags flags);
int				ft_uns_int(unsigned int number, t_flags flags);
int				ft_width(int width, int minus, int zero);
int				ft_handle(int c, t_flags flags, va_list args);
int				ft_printf(const char *fmt, ...);

#endif
