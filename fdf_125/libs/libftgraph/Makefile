NAME = libftgraph.a

SRC = ft_calc_fov.c	ft_in_radians.c ft_clear_depth_buffer.c ft_normal_rand.c \
	ft_twice_triangle_area.c

OBS = $(SRC:.c=.o)

$(NAME):
	gcc -c -Wall -Werror -Wextra $(SRC)
	ar rc $(NAME) $(OBS)

all: $(NAME)

clean:
	rm -rf $(OBS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
