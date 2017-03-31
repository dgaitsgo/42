/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 17:13:56 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/28 22:02:17 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

t_object			new_object(int type)
{
	t_object object;

	object.type = type;
	object.flags = 0;
	object.transformation.flags = 0;
	object.material.flags = 0;
	if (type == PLANE)
		new_canonical_plane(object.shape);
	if (type == SPHERE)
		new_canonical_sphere(object.shape);
	if (type == CYLINDER)
		new_canonical_cylinder(object.shape);
	if (type == CONE)
		new_canonical_cone(object.shape);
	return (object);
}

t_intersection		new_intersection(void)
{
	t_intersection	i;

	i.object = NULL;
	i.distance = MAX_BOUND;
	return (i);
}

t_transform			new_transformation(t_vector scale, t_vector rotation,
t_vector translation)
{
	t_transform t;

	t.scale = scale;
	t.rotation = rotation;
	t.translation = translation;
	return (t);
}

t_vector			new_vector(double x, double y, double z)
{
	t_vector		n;

	n.x = x;
	n.y = y;
	n.z = z;
	n.w = 0;
	return (n);
}
