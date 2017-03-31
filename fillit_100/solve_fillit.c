/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_fillit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 05:38:48 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/02/26 12:55:56 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			valid_values(t_fillit *s, t_cg *g, int temp)
{
	temp = g->y + s->diff[s->i][0][0];
	if (temp >= 0 && temp <= g->y_max)
	{
		temp = g->x + s->diff[s->i][0][1];
		if (temp >= 0 && temp <= g->y_max)
		{
			temp = g->y + s->diff[s->i][1][0];
			if (temp >= 0 && temp <= g->y_max)
			{
				temp = g->x + s->diff[s->i][1][1];
				if (temp >= 0 && temp <= g->y_max)
				{
					temp = g->y + s->diff[s->i][2][0];
					if (temp >= 0 && temp <= g->y_max)
					{
						temp = g->x + s->diff[s->i][2][1];
						if (temp >= 0 && temp <= g->y_max)
							return (1);
					}
				}
			}
		}
	}
	return (0);
}

int			good_pos(t_fillit *s, t_cg *g)
{
	if (valid_values(s, g, 0) == 0)
		return (0);
	if (g->grid[g->y][g->x] == '.')
	{
		if ((g->grid[g->y + s->diff[s->i][0][0]]
			[g->x + s->diff[s->i][0][1]] == '.') &&
			(g->grid[g->y + s->diff[s->i][1][0]]
			[g->x + s->diff[s->i][1][1]] == '.') &&
			(g->grid[g->y + s->diff[s->i][2][0]]
			[g->x + s->diff[s->i][2][1]] == '.'))
			return (1);
	}
	return (0);
}

void		place_piece(t_fillit *s, t_cg *g)
{
	char fc;

	fc = first_char(s->tets[s->i], 0, 0);
	g->grid[g->y][g->x] = fc;
	g->grid[g->y + s->diff[s->i][0][0]][g->x + s->diff[s->i][0][1]] = fc;
	g->grid[g->y + s->diff[s->i][1][0]][g->x + s->diff[s->i][1][1]] = fc;
	g->grid[g->y + s->diff[s->i][2][0]][g->x + s->diff[s->i][2][1]] = fc;
}

void		erase_piece(t_fillit *s, t_cg *g)
{
	char	fc;
	int		x;
	int		y;

	y = 0;
	fc = first_char(s->tets[s->i], 0, 0);
	while (y < g->y_max)
	{
		x = 0;
		while (x < g->x_max)
		{
			if (g->grid[y][x] == fc)
				g->grid[y][x] = '.';
			x++;
		}
		y++;
	}
}

int			place(t_fillit *s, t_cg *g, int x, int y)
{
	if (s->i == s->tetris)
		return (1);
	while (good_pos(s, g) != 1)
	{
		if (++g->x >= g->x_max)
		{
			g->x = 0;
			if (++g->y >= g->y_max)
				return (0);
		}
	}
	x = g->x;
	y = g->y;
	place_piece(s, g);
	s->i++;
	reset_vals(g);
	if (place(s, g, 0, 0))
		return (1);
	s->i--;
	erase_piece(s, g);
	g->x = ++x;
	g->y = y;
	return (place(s, g, 0, 0));
}
