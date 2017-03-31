# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/01 14:18:20 by dgaitsgo          #+#    #+#              #
#    Updated: 2016/10/10 22:40:52 by dgaitsgo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC_DIR = ./src
OBJ_DIR = ./obs
INC_DIR = ./inc

SRC_FILES = \
./src/weapon_bmps_convert.c \
./src/ft_strcmp.c \
./src/key_event.c \
./src/draw_sprites.c \
./src/weapon.c \
./src/raycast2.c \
./src/draw_ops.c \
./src/event.c \
./src/helpers.c \
./src/initialize.c \
./src/look.c \
./src/main.c \
./src/map.c \
./src/move.c \
./src/raycast.c \
./src/render.c \
./src/sprite.c \
./src/texture_ops.c \
./src/window.c \
./src/joystick.c \
./src/random.c \

OBJ_FILES = $(SRC_FILES:.c=.o) 

INC_FILES = \
./inc/wolf.h \

FLAGS = -Wall -Werror -Wextra

.PHONY: all, clean, fclean, re


$(NAME): $(OBJ_FILES)
	gcc -g3 -o $(NAME) $(OBJ_FILES) -framework SDL2 

all: $(NAME)

%.o:%.c $(INC_FILES)
	gcc -g -c $(FLAGS) -I$(INC_DIR) $< -o $@

clean:
	rm -rf $(OBJ_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all
