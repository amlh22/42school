# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amho <amho@student.42kl.edu.my>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/16 06:38:42 by amho              #+#    #+#              #
#    Updated: 2024/11/16 14:14:40 by amho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM	=	rm -rf

NAME	=	libft.a

INCLUDE	=	libft.h

# List of all source files
SOURCES	=	ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c  \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c

# List of object files created from source files.
OBJECTS	=	$(SOURCES:%.c=%.o)

# Default target
all: $(NAME)

# Target creates the library by archiving the object files. 
# Second line creates static library from object files.
# "$@" is target name, "$^" represents all the object files
$(NAME): $(OBJECTS)
	ar rcs $@ $^ 

# Compile source files into object files.
# "$<" refers to the first prerequisite of a rule, the corresponding .c file for
# the object file being created.
%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@
so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SOURCES)
	gcc -nostartfiles -shared -o libft.so $(OBJECTS)
	
# Target to remove all object files.
clean: 
	$(RM) $(OBJECTS)

# Target that calls clean and then removes the library file.
fclean: clean
	$(RM) $(NAME)

# Target to rebuild library from scratch. Cleans up entire build beforehand.
re: fclean all

# Declares the targets as phony targets, allowing them to be run regardless
.PHONY: all clean fclean re
