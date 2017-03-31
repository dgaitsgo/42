/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_fillit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 18:11:25 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/02/26 12:56:37 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	last_touch(char **s, char sol, int x, int y)
{
	int cubes;

	cubes = 0;
	s[y][x] = sol;
	if ((x + 1 < 4) && (s[y][x + 1] == sol) && (cubes++))
		s[y][x] = sol;
	else if ((y + 1 < 4) && (s[y + 1][x] == sol) && (cubes++))
		s[y][x] = sol;
	else if ((y - 1 >= 0) && (s[y - 1][x] == sol) && (cubes++))
		s[y][x] = sol;
	else if ((x - 1 >= 0) && (s[y][x - 1] == sol) && (cubes++))
		s[y][x] = sol;
	return (cubes);
}

int	orthogon(char **s, char sol, int x, int y)
{
	int cubes;

	cubes = 1;
	while (y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (s[y][x] == sol)
			{
				if ((x + 1 < 4) && (s[y][x + 1] == '#') && (cubes++))
					s[y][x + 1] = sol;
				if ((y + 1 < 4) && (s[y + 1][x] == '#') && (cubes++))
					s[y + 1][x] = sol;
				if ((y - 1 >= 0) && (s[y - 1][x] == '#') && (cubes++))
					s[y - 1][x] = sol;
				if ((x - 1 >= 0) && (s[y][x - 1] == '#') && (cubes++))
					s[y][x - 1] = sol;
			}
			if (s[y][x] == '#')
				cubes += last_touch(s, sol, x, y);
		}
		y++;
	}
	return (cubes);
}

int	find_first(char **s, char sol, int x, int y)
{
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (s[y][x] == '#')
			{
				s[y][x] = sol;
				return (orthogon(s, sol, x, y));
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	indi_verif(char **s, char sol, int x, int y)
{
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (s[y][x] != '.' && s[y][x] != '#')
			{
				return (0);
			}
			x++;
		}
		y++;
	}
	return (find_first(s, sol, 0, 0) == 4 ? 1 : 0);
}

int	verify(t_fillit *s)
{
	char sol;

	sol = 'a';
	s->tets[s->i] = NULL;
	s->tetris = s->i;
	reset_indexes(s);
	while (s->tets[s->i])
	{
		if ((indi_verif(s->tets[s->i], sol, 0, 0) == 1))
		{
			sol++;
			s->i++;
		}
		else
			return (0);
	}
	return (1);
}
