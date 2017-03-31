/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 18:07:55 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/28 23:07:29 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

void	calculate_world_intersection(t_object *object, t_ray world_ray,
t_intersection *intersection)
{
	intersection->point = matrix_transform_point(&intersection->point,
	object->transformation_matrix);
	intersection->normal = unit_vector(matrix_transform_direction(
	&intersection->normal, object->inverse_scale_times_rotation));
	intersection->distance = euclidean_distance3d(intersection->point,
	world_ray.origin);
}

t_ray	ray_world_to_object(t_ray world_ray, t_object *object)
{
	t_ray obj_ray;

	obj_ray.origin = matrix_transform_point(&world_ray.origin,
	object->inverse_transformation_matrix);
	obj_ray.direction = matrix_transform_direction(&world_ray.direction,
	object->inverse_transformation_matrix);
	obj_ray.len = vector_length(obj_ray.direction);
	obj_ray.direction = unit_vector(obj_ray.direction);
	return (obj_ray);
}

int		test_intersection(t_scene *scene, t_object *object, t_ray ray,
t_intersection *intersection)
{
	intersection->hit = scene->intersect_fn_pointers[object->type](
	ray_world_to_object(ray, object), intersection);
	if (intersection->hit != MISS)
	{
		intersection->ray = ray;
		calculate_world_intersection(object, ray, intersection);
		return (1);
	}
	return (0);
}
