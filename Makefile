# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dreis-ma <dreis-ma@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 20:32:35 by dreis-ma          #+#    #+#              #
#    Updated: 2023/04/08 14:57:12 by dreis-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
DEPS = libft/libft.a

SRC = src/push_swap.c src/validation.c src/list_setup.c src/sort_small.c src/sort_big.c src/sort_big_2.c src/sort_big_utils.c src/operations.c src/utils.c

OBJ = $(SRC:.c=.o)

NAME = push_swap

LIBFT = libft/libft.a

all: deps $(NAME)

deps:
	$(MAKE) -C ./libft
$(NAME): $(OBJ) $(DEPS)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

clean:
	$(MAKE) clean -C ./libft
	@rm -rf $(OBJ)

fclean: clean
	$(MAKE) $@ -C ./libft
	@rm -rf $(NAME)

re: fclean all
	$(MAKE) re -C ./libft
	
	
