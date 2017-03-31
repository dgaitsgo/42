/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_matrix_build.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 20:22:56 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/29 16:07:17 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

void		build_normal_to_world(t_matrix norm_to_world, t_transform *t)
{
	t_matrix	inverse_scale;
	t_matrix	rotation;

	build_inverse_scale_matrix(inverse_scale,
	t->scale.x, t->scale.y, t->scale.z);
	build_rotation_matrix(rotation, t->rotation.x,
	t->rotation.y, t->rotation.z);
	matrix_multiply(norm_to_world, rotation, inverse_scale);
}

void		handle_cylinder_edgecase(t_object *object)
{
	t_transform t;

	t = object->transformation;
	if ((t.translation.y <= 0 && t.rotation.y < 2.04672))
		object->transformation.rotation.y = 2.04672;
	if (t.rotation.x == 0 && t.rotation.y == 0 && t.rotation.z == 0)
		object->transformation.rotation.x = 3;
}

void		build_object_matrices(t_object *object)
{
	if (object->type == CYLINDER)
		handle_cylinder_edgecase(object);
	build_transformation_matrix(object->transformation_matrix,
	object->transformation);
	build_inverse_transformation_matrix(object->inverse_transformation_matrix,
	object->transformation);
	build_normal_to_world(object->inverse_scale_times_rotation,
	&object->transformation);
}
