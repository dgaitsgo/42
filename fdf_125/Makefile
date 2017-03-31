# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/04 02:52:45 by dgaitsgo          #+#    #+#              #
#    Updated: 2016/09/26 16:20:11 by dgaitsgo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC_DIR = ./src
OBJ_DIR = ./obs
INC_DIR = ./inc

SRC_FILES = src/clipping.c \
	./src/draw_ops.c \
	./src/colors.c \
	./src/edge.c \
	./src/events.c \
	./src/event_modify.c \
	./src/helpers.c \
	./src/fdf_mesh.c \
	./src/main.c \
	./src/gradient.c \
	./src/matrix_ops.c \
	./src/matrix_rotation.c \
	./src/mesh.c \
	./src/matrix.c \
	./src/obj_mesh.c \
	./src/vector_ops.c \
	./src/vertex_shift.c \
	./src/window.c \
	./src/tokenize.c \
	./src/scan.c \

OBJ_FILES = $(SRC_FILES:.c=.o)

INC_FILES = ft_graph.h \
	fdf.h \
	libtft.h \

FLAGS = -Wall -Werror -Wextra

.PHONY: all, clean, fclean, re, run


$(NAME): $(OBJ_FILES)
	make -C ./libs/libft
	make -C ./libs/libftgraph
	gcc -o $(NAME) $(OBJ_FILES) -L ./libs/libft/ -lft -L ./libs/libftgraph/ -lftgraph -L ./libs/ -lmlx -lft -framework OpenGL -framework AppKit

all: $(NAME)

%.o:%.c
	gcc -g -c $(FLAGS) $< -o $@

run: $(NAME)
	./$(NAME)

clean:
	make -C ./libs/libft/ fclean
	make -C ./libs/libftgraph/ fclean
	rm -rf $(OBJ_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all
