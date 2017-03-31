/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 19:42:23 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/05/08 22:32:29 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	order_vertices_by_y(t_vertex *min, t_vertex *mid, t_vertex *max)
{
	t_vertex	temp;

	if (min->pos.y > max->pos.y)
	{
		temp = *max;
		*max = *min;
		*min = temp;
	}
	if (mid->pos.y > max->pos.y)
	{
		temp = *max;
		*max = *mid;
		*mid = temp;
	}
	if (min->pos.y > mid->pos.y)
	{
		temp = *mid;
		*mid = *min;
		*min = temp;
	}
}

int		invalid_line(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (!(ft_isspace(s[i])) &&
			s[i] != '\0' && (!ft_isdigit(s[i]) &&
			s[i] != ',' && s[i] != '-'))
			return (1);
		if (s[i] == '-' && (s[i + 1]) == '\0')
			return (1);
		if (s[i] == '-' && (!ft_isdigit(s[i + 1])))
			return (1);
		i++;
	}
	return (0);
}
