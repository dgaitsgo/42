/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 15:52:08 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/10/08 09:50:28 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		on_edge(int x, int y)
{
	if (y == 0 || x == 0 || x == 1 || y == 1)
		return (1);
	if (x == X_MAX - 1 || y == Y_MAX - 1)
		return (1);
	return (0);
}

int		no_sprite_present(int x, int y, t_texture *texture)
{
	int i;

	i = 0;
	while (i < MAX_SPRITES)
	{
		if (x == intify(texture->sprite[i].x) ||
			y == intify(texture->sprite[i].y))
			return (0);
		i++;
	}
	return (1);
}

void	clear_squares_around_player(int **map)
{
	map[INITIAL_X][INITIAL_Y] = 0;
	map[INITIAL_X][INITIAL_Y + 1] = 0;
	map[INITIAL_X + 1][INITIAL_Y] = 0;
	map[INITIAL_X][INITIAL_Y - 1] = 0;
	map[INITIAL_X - 1][INITIAL_Y] = 0;
	map[INITIAL_X - 1][INITIAL_Y - 1] = 0;
	map[INITIAL_X + 1][INITIAL_Y + 1] = 0;
}

void	init_map(int **map, t_texture *texture)
{
	int x;
	int y;

	x = 0;
	while (x < X_MAX)
	{
		y = 0;
		while (y < Y_MAX)
		{
			if (on_edge(x, y))
				map[x][y] = 1;
			else if (x * y % 7 == 0 && no_sprite_present(x, y, texture))
				map[x][y] = random_int(8);
			else
				map[x][y] = 0;
			y++;
		}
		x++;
	}
	clear_squares_around_player(map);
}

int		**malloc_world_map(void)
{
	int	i;
	int **world_map;

	i = 0;
	world_map = malloc(sizeof(int *) * X_MAX);
	while (i < X_MAX)
	{
		world_map[i] = malloc(sizeof(int) * Y_MAX);
		i++;
	}
	return (world_map);
}
