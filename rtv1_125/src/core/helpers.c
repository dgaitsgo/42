/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 18:01:12 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/29 00:54:29 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

t_range					range(double min, double max)
{
	t_range	range;

	range.min = min;
	range.max = max;
	return (range);
}

void					swap(double *a, double *b)
{
	double c;

	c = *a;
	*a = *b;
	*b = c;
}

void					free_if(void *ptr)
{
	if (ptr)
		free(ptr);
}

void					reset_intersection(t_intersection *i)
{
	i->distance = MAX_BOUND;
	i->object = NULL;
}

void					copy_intersection(t_intersection *dst,
										t_intersection *src)
{
	dst->id = src->id;
	dst->distance = src->distance;
	dst->object = src->object;
	dst->point = src->point;
	dst->normal = src->normal;
	dst->ray = src->ray;
	dst->hit = src->hit;
}
