# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/14 18:44:13 by ellaca-f          #+#    #+#              #
#    Updated: 2022/04/13 12:43:35 by ellaca-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC=gcc

CFLAGS= -Wall -Wextra -Werror -g -O3

RM=rm -f

LDFLAGS=-L.

LDLIBS=-lft

HDDIRS=-I includes/

SRC=ft_memset.c ft_bzero.c \
ft_memmove.c ft_memcmp.c \
ft_strlen.c ft_strdup.c ft_strchr.c \
ft_strrev.c ft_strcmp.c ft_strcpy.c \
ft_strlcat.c ft_strrchr.c ft_strnstr.c ft_strlcpy.c \
ft_strncmp.c ft_atoi.c \
ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_toupper.c ft_tolower.c \
ft_strmapi.c \
ft_strtrim.c ft_split.c \
ft_itoa.c ft_calloc.c \
ft_putchar_fd.c \

OBJ=$(SRC:.c=.o)

$(NAME): libft.h
	$(CC) $(CFLAGS) -c $(SRC) $(HDDIRS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

bonus: all

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean
