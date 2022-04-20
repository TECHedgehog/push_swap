# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 18:46:52 by ellaca-f          #+#    #+#              #
#    Updated: 2022/04/20 17:28:40 by ellaca-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

THIS_DIR := ./

CC := gcc
RM := rm -rf
CFLAGS := -Wall -Werror -Wextra
DFLAGS := -g

LIBFT_DIR := ./libft
LIBFT := libft.a

BUILD_DIR := ./build

SRC_DIR := ./src
INC_DIR := ./includes
HDDIRS := -I $(INC_DIR)

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(HDDIRS) $(LIBFT) -o $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(DFLAGS) $(HDDIRS) -c $< -o $@

$(LIBFT):
	@echo "\n--------Setting up LIBFT---------------------\n"
	@make -C $(LIBFT_DIR)
	@echo "\n--------Copying LIBFT lib to main dir--------\n"
	@mv $(LIBFT_DIR)/$(LIBFT) .
	@cp $(LIBFT_DIR)/libft.h $(INC_DIR)
	@echo "--------LIBFT done---------------------------\n"

all: $(NAME)

clean:
	@$(RM) $(BUILD_DIR)

fclean: clean
	@$(RM) $(LIBFT) $(LIBFT_DIR)/*.o $(NAME) $(INC_DIR)/libft.h

re: fclean all

debug: clean $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(DFLAGS) $(OBJS) $(HDDIRS) $(LIBFT) -o $(NAME)

.PHONY: all clean fclean re debug test