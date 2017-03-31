/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_prep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 05:34:19 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/02/26 12:57:03 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	find_all_four(int **pos, char **s)
{
	int y;
	int x;
	int i;

	i = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (s[y][x] >= 'a' && s[y][x] <= 'z')
			{
				s[y][x] -= 32;
				pos[i][0] = y;
				pos[i][1] = x;
				i++;
			}
			x++;
		}
		y++;
	}
}

int		**pos_table(char **s)
{
	int **pos;

	pos = 0;
	pos = get_mem(pos);
	find_all_four(pos, s);
	return (pos);
}

void	diff_table(int **pos, int **diff)
{
	int i;

	i = 0;
	while (i < 3)
	{
		diff[i][0] = pos[i + 1][0] - pos[0][0];
		diff[i][1] = pos[i + 1][1] - pos[0][1];
		i++;
	}
}

void	loop(t_fillit *s, t_cg *g)
{
	if (place(s, g, 0, 0) == 1)
		return ;
	else
	{
		g->x = 0;
		g->y = 0;
		expand_map(g);
		loop(s, g);
	}
}

int		solve_and_display(t_fillit *s)
{
	int		**pos;
	t_cg	g;

	pos = 0;
	reset_indexes(s);
	s->diff = get_triple_mem(s->diff, s->tetris);
	while (s->i < s->tetris)
	{
		pos = pos_table(s->tets[s->i]);
		diff_table(pos, s->diff[s->i]);
		s->i++;
	}
	initialize_grid(&g);
	s->i = 0;
	s->placed = 0;
	loop(s, &g);
	print_grid(&g);
	return (1);
}
