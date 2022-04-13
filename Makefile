# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ellaca-f <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 18:46:52 by ellaca-f          #+#    #+#              #
#    Updated: 2022/04/13 12:44:25 by ellaca-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

TEST1 := 1 2 3 4 5 6 7 8 9 10 12 13 14 15 16 17 18 19 20 21 22 24 23
TEST2 := 10 8 2 9 3 6 1 5 4 11 7

CC := gcc
RM := rm -rf
CFLAGS := -Wall -Werror -Wextra
DFLAGS := -g
LFLAGS := -fsanitize=address
ASAND_OPT := ASAN_OPTIONS=abort_on_error=1
ASAN_OPT := ASAN_OPTIONS=detect_leaks=1

LIBFT_DIR := ./Libft
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

test: all
	./$(NAME) $(TEST1)
	./$(NAME) $(TEST2)

.PHONY: all clean fclean re debug test