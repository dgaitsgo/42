/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 16:38:00 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/26 16:30:37 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

int			light_is_visible(t_intersection intersection,
t_scene *scene, t_vector *light)
{
	double		light_distance;
	t_ray		ray;

	light_distance = euclidean_distance3d(intersection.point, *light);
	ray.origin = intersection.point;
	ray.direction = unit_vector(vector_subtract(*light, intersection.point));
	intersection = intersect_scene(ray, scene);
	if (intersection.distance < light_distance)
		return (0);
	return (1);
}

void		reflect(t_vector *color, t_intersection intersection,
t_scene *scene, int depth)
{
	t_vector	s_color;
	t_vector	r;
	t_ray		n;

	set_vector(&s_color, 0, 0, 0);
	r = vector_add(vector_scale(vector_scale(intersection.normal,
	dot_product(intersection.ray.direction, intersection.normal)), -2),
	intersection.ray.direction);
	n.origin = vector_add(intersection.point, r);
	n.direction = r;
	n.direction = unit_vector(n.direction);
	s_color = *trace_container(n, scene, &s_color, ++depth);
	*color = vector_add(*color, vector_multiply(vector_scale(s_color,
	intersection.object->material.reflective),
	intersection.object->material.color));
}

void		refract(t_vector *color, t_intersection intersection, t_scene *scene, int depth)
{
	int			sign;
	t_ray		refracted_ray;
	double		dot;
	double		n;
	double		n1;
	double		n2;
	t_vector	N;

	n1 = AR_INDEX;
	n2 = intersection.object->material.refraction;
	n = n1 / n2;
	N = vector_scale(intersection.normal, (double)intersection.hit);
	double cosI = -dot_product(N, intersection.ray.direction);
	double cosT2 = 1 - n * n * (1 - cosI * cosI);
	if (cosT2 > MIN_PRECISION)
	{
		double		temp = n * cosI - sqrtf(cosT2);
		t_vector	T = vector_multiply(vector_const_add(vector_scale(intersection.ray.direction, n), temp), N);

		t_vector	s_color;
		set_vector(&s_color, 0, 0, 0);
		refracted_ray.origin = vector_add(intersection.point, vector_scale(T, MIN_PRECISION));
		refracted_ray.direction = unit_vector(T);
		s_color = *trace_container(refracted_ray, scene, &s_color, ++depth); 
		AR_INDEX = n2;
		*color = vector_add(s_color, *color);
	}
}

t_vector	*shader(t_intersection intersection,
t_scene *scene, t_vector *color, int depth)
{
	t_object	*object;
	int			i;

	i = 0;
	object = intersection.object;
	while (i < scene->n_lights)
	{
		if (light_is_visible(intersection, scene, &scene->light[i]))
		{
			phong_shading(color, intersection, &scene->light[i]);
			if ((object->material.reflective > 0.0) && (depth < MAX_DEPTH))
				reflect(color, intersection, scene, depth);
			if ((object->material.refraction > 0.0) && (depth < MAX_DEPTH))
				refract(color, intersection, scene, depth);
		}
		*color = vector_add(*color,
		vector_scale(object->material.color, object->material.ambient));
		i++;
	}
	return (color);
}
