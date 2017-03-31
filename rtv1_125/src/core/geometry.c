/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 18:00:20 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/19 18:00:57 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

double		degrees_to_radians(double degrees)
{
	return (PI * degrees / 180);
}

double		euclidean_distance3d(t_vector a, t_vector b)
{
	return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2)));
}

t_vector	solve_parametric(t_ray ray, double t)
{
	t_vector	res;

	res = vector_add(ray.origin, vector_scale(ray.direction, t));
	return (res);
}
