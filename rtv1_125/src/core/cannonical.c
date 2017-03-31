/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cannonical.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 16:07:50 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/29 16:11:20 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

void	new_canonical_plane(void *ptr)
{
	t_plane plane;

	plane.flags = 0;
	set_vector(&plane.point, 0, 0, 0);
	set_vector(&plane.normal, 0, 1, 0);
	ptr = &plane;
}

void	new_canonical_sphere(void *ptr)
{
	t_sphere sphere;

	sphere.flags = 0;
	ptr = &sphere;
}

void	new_canonical_cylinder(void *ptr)
{
	t_cylinder cylinder;

	cylinder.flags = 0;
	ptr = &cylinder;
}

void	new_canonical_cone(void *ptr)
{
	t_cone cone;

	cone.flags = 0;
	ptr = &cone;
}
