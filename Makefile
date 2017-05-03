# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ramichia <ramichia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/28 12:22:20 by ramichia          #+#    #+#              #
#    Updated: 2017/05/03 13:57:17 by ramichia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
CC = gcc
FLAGS = -Wall -Wextra -Werror

LIB = ./libft/libft.a
LIB_PATH = ./libft

SRC = src/parsing_rooms.c src/check.c src/list_ops.c src/check_path.c \
		src/find_link.c src/find_path.c src/find_recursive_path.c \
		src/print_error.c src/walk_of_ants.c src/main.c

HEADER = lem_in.h

OBJS = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
	@ $(CC) -g $(FLAGS) $(SRC) $(LIB) -o $(NAME)

$(LIB):
	@make -C $(LIB_PATH)
	@echo "make ok"

%.o: %.c
	@$(CC) $(FLAGS)  -o $@ -c $<
clean:
	@rm -f $(OBJS)
	@make clean -C ./libft
	@echo "clean OK"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft
	@echo "LIBRARY DELETED"

re: fclean all
