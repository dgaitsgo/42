# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/08 18:14:13 by dgaitsgo          #+#    #+#              #
#    Updated: 2016/05/06 04:00:23 by dgaitsgo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = parse_fillit.c verify_fillit.c helpers_fillit.c tests_fillit.c \
	solve_fillit.c prep_solution.c

OBS = $(SRC:.c=.o)

all: $(NAME)

.PHONY: all, clean, fclean, re

$(NAME): $(OBS)
	make -C libft
	gcc -o $(NAME) $(OBS) -lft -L ./libft

%.o:%.c
	gcc -c -Wall -Werror -Wextra $< -o $@

clean:
	make -C libft/ fclean
	rm -rf $(OBS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
