# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpenaran <gpenaran@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/27 15:24:13 by gpenaran          #+#    #+#              #
#    Updated: 2020/12/03 12:13:17 by gpenaran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = 	ft_printf.c \
		functions/ft_text.c \
		functions/ft_flags.c \
		functions/ft_hexa_pointer.c \
		functions/ft_int.c \
		functions/ft_uns_int.c \
		functions/ft_utils.c \
		libcft/ft_isdigit.c \
		libcft/ft_itoa.c \
		libcft/ft_u_itoa.c \
		libcft/ft_putchar.c \
		libcft/ft_putstr.c \
		libcft/ft_str_tolower.c \
		libcft/ft_strdup.c \
		libcft/ft_strlen.c \
		libcft/ft_utl_base.c 

OBJECTS = ft_printf.o \
		ft_text.o \
		ft_flags.o \
		ft_hexa_pointer.o \
		ft_int.o \
		ft_uns_int.o \
		ft_utils.o \
		ft_isdigit.o \
		ft_itoa.o \
		ft_u_itoa.o \
		ft_putchar.o \
		ft_putstr.o \
		ft_str_tolower.o \
		ft_strdup.o \
		ft_strlen.o \
		ft_utl_base.o

INCLUDES = ft_printf.h


all: $(NAME)

$(NAME): $(OBJECTS)

$(OBJECTS): $(SRCS) $(INCLUDES)
	@gcc -Wextra -Werror -Wall -c $(SRCS)
	@ar rcs $(NAME) $(OBJECTS)

clean:
	rm -rf $(OBJECTS)
	
fclean: clean
	rm -rf $(NAME)

re: fclean all