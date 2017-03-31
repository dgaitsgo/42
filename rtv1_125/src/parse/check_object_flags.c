/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_object_flags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 16:58:33 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/29 15:56:48 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"
#include "parse.h"
#include "flags.h"

void	check_cylinder_flags(t_cylinder *cylinder)
{
	if (cylinder)
		return ;
}

void	check_cone_flags(t_cone *cone)
{
	if (cone)
		return ;
}

void	check_plane_flags(t_plane *plane)
{
	if (plane)
		return ;
}

void	check_sphere_flags(t_sphere *sphere)
{
	if (sphere)
		return ;
}

void	check_object_flags(t_object *object)
{
	if (!BIT_CHECK(object->flags, TRANSFORM_DEFINED))
		object->transformation = new_transformation(new_vector(1, 1, 1),
		new_vector(0, 0, 0), new_vector(0, 0, -10));
	if (!BIT_CHECK(object->flags, MATERIAL_DEFINED))
		object->material = random_material();
	if (object->type == SPHERE)
		check_sphere_flags((t_sphere *)object->shape);
	if (object->type == CONE)
		check_cone_flags((t_cone *)object->shape);
	if (object->type == CYLINDER)
		check_cylinder_flags((t_cylinder *)object->shape);
	if (object->type == PLANE)
		check_plane_flags((t_plane *)object->shape);
}
