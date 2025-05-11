# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amho <amho@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/11 23:13:08 by amho              #+#    #+#              #
#    Updated: 2025/05/11 23:22:01 by amho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM	=	rm -rf
AR	=	ar rcs

NAME	=	libftprintf.a
INCLUDE	=	ft_printf.h

SOURCES =	ft_printf.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putint.c \
		ft_putuint.c \
		ft_puthex.c \
		ft_putptr.c \

OBJECTS	=	$(SOURCES:%.c=%.o)

all:	$(NAME)

$(NAME): $(OBJECTS)
	$(AR)  $@ $^

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

clear: fclean clear

.PHONY: all clean fclean re
