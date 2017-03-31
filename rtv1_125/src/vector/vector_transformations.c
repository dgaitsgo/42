/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_transformations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 21:44:31 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/25 11:33:16 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

t_vector		matrix_transform_point(t_vector *pnt, t_matrix m)
{
	t_vector	inv;

	inv.x = pnt->x * m[0][0] + pnt->y * m[0][1] + pnt->z * m[0][2] + m[0][3];
	inv.y = pnt->x * m[1][0] + pnt->y * m[1][1] + pnt->z * m[1][2] + m[1][3];
	inv.z = pnt->x * m[2][0] + pnt->y * m[2][1] + pnt->z * m[2][2] + m[2][3];
	inv.w = 1;
	return (inv);
}

t_vector		matrix_transform_direction(t_vector *dir, t_matrix m)
{
	t_vector	inv;

	inv.x = dir->x * m[0][0] + dir->y * m[0][1] + dir->z * m[0][2];
	inv.y = dir->x * m[1][0] + dir->y * m[1][1] + dir->z * m[1][2];
	inv.z = dir->x * m[2][0] + dir->y * m[2][1] + dir->z * m[2][2];
	inv.w = 0;
	return (inv);
}
