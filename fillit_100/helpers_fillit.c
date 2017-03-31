/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_fillit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 17:58:48 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/03/22 22:28:21 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	reset_vals(t_cg *g)
{
	g->x = 0;
	g->y = 0;
}

void	initialize_grid(t_cg *g)
{
	int i;

	i = 0;
	g->grid = (char **)malloc(105);
	while (i < 104)
	{
		g->grid[i] = (char *)malloc(sizeof(char) * 105);
		ft_memset(g->grid[i], 0, 104);
		i++;
	}
	g->grid[i] = NULL;
	g->grid[0][0] = '.';
	g->grid[0][1] = '.';
	g->grid[1][0] = '.';
	g->grid[1][1] = '.';
	g->x = 0;
	g->y = 0;
	g->x_max = 2;
	g->y_max = 2;
}

int		**get_mem(int **pos)
{
	int i;

	i = 0;
	pos = (int **)malloc(sizeof(int *) * 4);
	while (i < 4)
	{
		pos[i] = (int *)malloc(sizeof(int) * 2);
		ft_memset(pos[i], 0, 2);
		i++;
	}
	return (pos);
}

void	expand_map(t_cg *g)
{
	int y;
	int x;

	x = 0;
	y = 0;
	g->y_max += 1;
	g->x_max += 1;
	while (y < g->y_max)
	{
		g->grid[y][g->x_max - 1] = '.';
		y++;
	}
	while (x < g->x_max)
	{
		g->grid[g->y_max - 1][x] = '.';
		x++;
	}
}

int		***get_triple_mem(int ***diff, int tetris)
{
	int squares;
	int index;

	index = 0;
	diff = (int ***)malloc(sizeof(int **) * tetris);
	while (index < tetris)
	{
		squares = 0;
		diff[index] = (int **)malloc(sizeof(int *) * 3);
		while (squares < 4)
		{
			diff[index][squares] = (int *)malloc(sizeof(int) * 2);
			ft_memset(diff[index][squares], 0, 2);
			squares++;
		}
		index++;
	}
	return (diff);
}
