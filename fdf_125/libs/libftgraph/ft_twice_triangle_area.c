/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twice_triangle_area.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 16:07:23 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/05/07 15:52:37 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

float		ft_twice_triangle_area(t_vertex *min, t_vertex *max, t_vertex *mid)
{
	float x1;
	float x2;
	float y1;
	float y2;

	x1 = max->pos.x - min->pos.x;
	x2 = mid->pos.x - min->pos.x;
	y1 = max->pos.y - min->pos.y;
	y2 = mid->pos.y - min->pos.y;
	return (x1 * y2 - x2 * y1);
}
