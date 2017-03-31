/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong_shading.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 16:38:25 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/21 00:24:09 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

t_vector	calculate_lambert(t_intersection intersection, t_vector light)
{
	double		lambert_amt;
	double		contribution;
	t_vector	lambert;

	lambert_amt = 0;
	contribution = 0;
	lambert = new_vector(0, 0, 0);
	contribution = dot_product(unit_vector(vector_subtract(light,
	intersection.point)), intersection.normal);
	if (contribution > 0)
		lambert_amt += contribution;
	lambert = vector_scale(intersection.object->material.color, lambert_amt);
	return (lambert);
}

t_vector	calculate_specular(t_intersection intersection, t_vector light)
{
	t_vector	l;
	t_vector	r;
	double		dot;
	double		spec;

	l = unit_vector(vector_subtract(light, intersection.point));
	r = vector_add(vector_scale(vector_scale(intersection.normal,
	dot_product(l, intersection.normal)), -2), l);
	dot = dot_product(intersection.ray.direction, r);
	if (dot > 0)
	{
		spec = powf(dot, 20) * intersection.object->material.specular;
		if (spec)
		{
			return (vector_scale(intersection.object->material.color, spec));
		}
	}
	return (new_vector(0, 0, 0));
}

void		phong_shading(t_vector *color, t_intersection intersection,
t_vector *light)
{
	if (intersection.object->material.lambert)
	{
		*color = vector_add(*color,
		calculate_lambert(intersection, *light));
	}
	if (intersection.object->material.specular)
	{
		*color = vector_add(*color,
		calculate_specular(intersection, *light));
	}
}
