/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 23:04:51 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/23 02:26:56 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

/*
template<typename T, precision P>
	GLM_FUNC_QUALIFIER mat<4, 4, T, P> lookAtLH
	(
		vec<3, T, P> const & eye,
		vec<3, T, P> const & center,
		vec<3, T, P> const & up
	)
	{
		vec<3, T, P> const f(normalize(center - eye));
		vec<3, T, P> const s(normalize(cross(up, f)));
		vec<3, T, P> const u(cross(f, s));

		mat<4, 4, T, P> Result(1);
		Result[0][0] = s.x;				Result[0][1] = u.x;				Result[0][2] = f.x; 
		Result[1][0] = s.y;				Result[1][1] = u.y;				Result[1][2] = f.y;
		Result[2][0] = s.z;				Result[2][1] = u.z;				Result[2][2] = f.z;  
		Result[3][0] = -dot(s, eye);	Result[3][1] = -dot(u, eye);	Result[3][2] = -dot(f, eye);
		return Result;
	}
*/

void		look_at(t_matrix m, t_vector eye, t_vector center, t_vector up)
{
	t_vector 	f;
	t_vector	s;
	t_vector	u;

	zero_matrix(m);
	f = unit_vector(vector_subtract(center, eye));
	s = unit_vector(vector_cross(up, f));
	u = vector_cross(f, s);
	m[0][0] = s.x;					m[0][1] = u.x;					m[0][2] = f.x;
	m[1][0] = s.y;					m[1][1] = u.y;					m[1][2] = f.y;
	m[2][0] = s.z;					m[2][1] = u.z;					m[2][2] = f.z;
	m[3][0] = -dot_product(s, eye);	m[3][1] = -dot_product(u, eye);	m[3][2] = -dot_product(f, eye);
}

void	projection_matrix(t_matrix m, float fov, float aspect_ratio)
{
	float range;
	float sx;
	float sy;
	float sz;
	float pz;

	range = tan(in_radians(fov * 0.5)) * Z_NEAR;
	sx = (2 * Z_NEAR) / (range * aspect_ratio + range * aspect_ratio);
	sy = Z_NEAR / range;
	sz = -(Z_FAR + Z_NEAR) / (Z_FAR - Z_NEAR);
	pz = -(2 * Z_FAR * Z_NEAR) / (Z_FAR - Z_NEAR);
	zero_matrix(m);
	m[0][0] = sx;
	m[1][1] = sy; 
	m[2][2] = sz; 
	m[2][3] = -1;
	m[3][2] = pz;
}


void	init_camera(t_camera *camera)
{
	projection_matrix(camera->projection, FOV, ASPECT_RATIO);
	set_vector(&camera->forward,0, 0, 1);
	set_vector(&camera->up, 0, 1, 0);
}
