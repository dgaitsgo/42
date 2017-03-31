/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_fillit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 18:00:28 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/02/26 12:57:07 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_grid(t_cg *g)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < g->y_max)
	{
		x = 0;
		while (x < g->x_max)
		{
			ft_putchar(g->grid[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

int		check_last(char **s, int x, int y)
{
	if (s[0][0] == '\0')
		return (1);
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (s[y][x] != '.' || s[y][x] != '#')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
