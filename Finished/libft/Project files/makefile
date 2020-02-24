# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpenaran <gpenaran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 15:09:01 by gpenaran          #+#    #+#              #
#    Updated: 2019/11/21 13:26:37 by gpenaran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

SRCS		=	ft_atoi.c\
				ft_bzero.c\
				ft_calloc.c\
				ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c\
				ft_itoa.c\
				ft_memccpy.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_memcpy.c\
				ft_memmove.c\
				ft_memset.c\
				ft_putchar_fd.c\
				ft_putchar.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c\
				ft_putnbr.c\
				ft_putstr_fd.c\
				ft_putstr.c\
				ft_split.c\
				ft_strcat.c\
				ft_strchr.c\
				ft_strcmp.c\
				ft_strcpy.c\
				ft_strdup.c\
				ft_strjoin.c\
				ft_strlcat.c\
				ft_strlcpy.c\
				ft_strlen.c\
				ft_strmapi.c\
				ft_strncat.c\
				ft_strncmp.c\
				ft_strncpy.c\
				ft_strnstr.c\
				ft_strrchr.c\
				ft_strstr.c\
				ft_strtrim.c\
				ft_substr.c\
				ft_tolower.c\
				ft_toupper.c\
				ft_lstsize.c\

BON			=	ft_lstnew_bonus.c\

GCC			=	@gcc -Wall -Wextra -Werror

OBJS		=	$(SRCS:.c=.o)

BONOBJS		=	$(SRCS:.c=.o)

INCLUDES 	=	./

all: $(NAME)

$(NAME):	$(SRCS) libft.h
	$(GCC) -I$(INCLUDES) -c $(SRCS)
	-@ar rc $(NAME) $(OBJS)
	-@ranlib $(NAME)

bonus:		$(BON) $(SRCS) libft.h
	$(GCC) -I$(INCLUDES) -c $(BON) $(SRCS)
	-@ar rc $(NAME) $(BONOBJS) $(OBJS)
	-@ranlib $(NAME)
	
clean:
	@/bin/rm -f $(OBJS) $(BONOBJS)

fclean:	clean
	@/bin/rm -f $(NAME)

re: 
	make fclean all

	