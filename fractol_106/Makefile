# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/06 02:50:17 by dgaitsgo          #+#    #+#              #
#    Updated: 2016/10/08 14:08:40 by dgaitsgo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_DIR = ./src
OBJ_DIR = ./obs
INC_DIR = ./inc

SRC_FILES = ./src/julia.c \
	./src/draw_ops.c \
	./src/main.c \
	./src/newton.c \
	./src/helpers.c \
	./src/window.c \
	./src/init_dispatch.c \
	./src/redefine.c \
	./src/move.c \
	./src/mandelbrot.c \
	./src/zoom_in.c \
	./src/zoom_out.c \
	./src/shift_julia.c \

OBJ_FILES = $(SRC_FILES:.c=.o)

INC_FILES = fractal.h \

FLAGS = -I$(INC_DIR)

.PHONY: all, clean, fclean, re, run

$(NAME): $(OBJ_FILES)
	gcc -o $(NAME) $(OBJ_FILES) -L./lib/ -lmlx -framework OpenGL -framework AppKit 

all: $(NAME)

%.o:%.c
	gcc -c $(FLAGS) $< -o $@

run: $(NAME)
	./$(NAME)

clean:
	rm -rf $(OBJ_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all
