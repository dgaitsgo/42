/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 21:31:16 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/28 23:07:30 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"
#include "flags.h"

void	set_up_sphere_coefficients(t_quadratic *q, t_vector d, t_vector p)
{
	q->a = 1;
	q->b = 2 * dot_product(d, p);
	q->c = dot_product(p, p) - 1;
}

int		intersect_sphere(t_ray obj_ray, t_intersection *intersection)
{
	t_quadratic		q;
	int				hit;

	set_up_sphere_coefficients(&q, obj_ray.direction, obj_ray.origin);
	if ((hit = solve_quadratic(&q)))
	{
		intersection->point = solve_parametric(obj_ray, q.t1);
		intersection->distance = q.t1;
		intersection->normal = unit_vector(intersection->point);
		hit == FROM_INSIDE ? intersection->normal =
		vector_scale(intersection->normal, -1): intersection->normal;
	}
	return (hit);
}
