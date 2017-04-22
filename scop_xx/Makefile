# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/31 16:35:38 by dgaitsgo          #+#    #+#              #
#    Updated: 2017/04/22 12:31:21 by dgaitsgo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = scop 

SRC_DIR = ./src
OBJ_DIR = ./obs
INC_DIR = ./inc

SRC_FILES = \
$(SRC_DIR)/transform.c \
$(SRC_DIR)/model.c \
$(SRC_DIR)/main.c \
$(SRC_DIR)/window.c \
$(SRC_DIR)/open_gl.c \
$(SRC_DIR)/constructors.c \
$(SRC_DIR)/parse_mesh.c \
$(SRC_DIR)/helpers.c \
$(SRC_DIR)/math.c \
$(SRC_DIR)/render.c \
$(SRC_DIR)/debug_open_gl.c \
$(SRC_DIR)/debug.c \
$(SRC_DIR)/file_helpers.c \
$(SRC_DIR)/fetch_memory.c \
$(SRC_DIR)/push_face.c \
$(SRC_DIR)/shader.c \
$(SRC_DIR)/order_data.c \
$(SRC_DIR)/matrix_rotate.c \
$(SRC_DIR)/matrix.c \
$(SRC_DIR)/camera.c \
$(SRC_DIR)/vector_constructors.c \

OBJ_FILES = $(SRC_FILES:.c=.o)

INC_FILES = \
$(INC_DIR)/scop.h \
$(INC_DIR)/libft.h \
$(INC_DIR)/get_next_line.h \
$(INC_DIR)/macros.h \
$(INC_DIR)/matrix.h \
$(INC_DIR)/flags.h \
$(INC_DIR)/transform.h \
$(INC_DIR)/vector.h \
$(INC_DIR)/model.h \
$(INC_DIR)/window.h \
$(INC_DIR)/ft_math.h \
$(INC_DIR)/helpers.h \

LIB_DIR = ./lib/libft

FLAGS = #-Wall -Wextra -Werror -g

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ_FILES)
	make -C ./lib/libft
	gcc $(FLAGS) -o $(NAME) $(OBJ_FILES) -L$(LIB_DIR) -lft -F/Library/Frameworks -framework SDL2 -framework OpenGL

%.o:%.c $(INC_FILES)
	gcc -c $(FLAGS) -I$(INC_DIR) $< -o $@

clean:
	make -C ./lib/libft/ clean
	rm -rf $(OBJ_FILES)

fclean: clean
	make -C ./lib/libft/ fclean
	rm -rf $(NAME)

re: fclean all
