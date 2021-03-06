# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/26 14:32:25 by dgaitsgo          #+#    #+#              #
#    Updated: 2017/03/08 14:58:00 by dgaitsgo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

SRC_DIR = ./src
OBJ_DIR = ./obs
INC_DIR = ./inc

SRC_FILES = \
./src/core/events.c \
./src/core/cannonical.c \
./src/core/color.c \
./src/core/color2.c \
./src/core/cone_intersection.c \
./src/core/constructors.c \
./src/core/cylinder_intersection.c \
./src/core/default_constructors.c \
./src/core/geometry.c \
./src/core/helpers.c \
./src/core/initializations.c \
./src/core/intersection.c \
./src/core/inverse_rotation_matrix.c \
./src/core/inverse_transformations.c \
./src/core/main.c \
./src/core/math.c \
./src/core/matrix.c \
./src/core/object_matrix_build.c \
./src/core/phong_shading.c \
./src/core/plane_intersection.c \
./src/core/random.c \
./src/core/render.c \
./src/core/rotation_matrix.c \
./src/core/shader.c \
./src/core/sphere_intersection.c \
./src/core/transformation_matrix.c \
./src/core/window.c \
./src/parse/character_check.c \
./src/parse/count_words_and_length.c \
./src/parse/file_to_string.c \
./src/parse/flags.c \
./src/parse/get_next_line.c \
./src/parse/only_one_word.c \
./src/parse/parse.c \
./src/parse/check_flags.c \
./src/parse/check_object_flags.c \
./src/parse/parse_camera.c \
./src/parse/parse_element.c \
./src/parse/parse_error.c \
./src/parse/parse_material.c \
./src/parse/parse_object.c \
./src/parse/parse_stream_controls.c \
./src/parse/parse_tools.c \
./src/parse/parse_transform.c \
./src/parse/parse_vector_and_scalar.c \
./src/parse/parse_window.c \
./src/parse/remove_white_space.c \
./src/parse/tokenize.c \
./src/vector/vector.c \
./src/vector/vector_basic_ops.c \
./src/vector/vector_constructors.c \
./src/vector/vector_scale.c \
./src/vector/vector_transformations.c \

OBJ_FILES = $(SRC_FILES:.c=.o) #$(addprefix $(OBJ_DIR)/,$(notdir $(SRC_FILES:.c=.o)))

INC_FILES = \
./inc/camera.h \
./inc/color.h \
./inc/enums.h \
./inc/flags.h \
./inc/geometry.h \
./inc/get_next_line.h \
./inc/intersection.h \
./inc/libft.h \
./inc/macros.h \
./inc/maths.h \
./inc/matrix.h \
./inc/object.h \
./inc/parse.h \
./inc/random.h \
./inc/ray.h \
./inc/ray_trace.h \
./inc/shader.h \
./inc/shapes.h \
./inc/transform.h \
./inc/vector.h \
./inc/window.h \

LIB_DIR = ./lib/libft

FLAGS = -Wall -Werror -Wextra

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ_FILES)
	make -C ./lib/libft
	gcc -g3 -o $(NAME) $(OBJ_FILES) -L$(LIB_DIR) -lft -L./lib/ -lmlx -framework OpenGL -framework AppKit

%.o:%.c $(INC_FILES)
	gcc -g -c -I$(INC_DIR) $< -o $@

clean:
	make -C ./lib/libft/ clean
	rm -rf $(OBJ_FILES)

fclean: clean
	make -C ./lib/libft/ fclean
	rm -rf $(NAME)

re: fclean all
