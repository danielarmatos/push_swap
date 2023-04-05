# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dreis-ma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 20:32:35 by dreis-ma          #+#    #+#              #
#    Updated: 2023/03/28 20:32:42 by dreis-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
DEPS = libft/libft.a

SRC = src/push_swap.c

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
	
	
