/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 10:44:07 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/18 21:23:01 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"
/*
void	perspective_matrix(t_matrix m)
{
	float		z_range;
	float		fov;

	fov = calc_fov(FOV);
	z_range = Z_NEAR - Z_FAR;
	m[0][0] = 1.0f / (fov * ASPECT_RATIO);
	m[0][1] = 0;
	m[0][2] = 0;
	m[0][3] = 0;

	m[1][0] = 0;
	m[1][1] = 1.0f / fov;
	m[1][2] = 0;
	m[1][3] = 0;

	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = (-Z_NEAR - Z_FAR) / z_range;
	m[2][3] = 2 * Z_FAR * Z_NEAR / z_range;

	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 1;
	m[3][3] = 0;
}
*/
void	perspective_matrix(t_matrix m)
{
	float	range = tan(in_radians(FOV) * 0.5f) * Z_NEAR;
	float	sx = (2.0f * Z_NEAR) / (range * ASPECT_RATIO + range * ASPECT_RATIO) ;
	float	sy = Z_NEAR / range;
	float	sz = -(Z_FAR + Z_NEAR) / (Z_FAR - Z_NEAR);
	float 	pz = -(2.0f * Z_FAR * Z_NEAR) / (Z_FAR - Z_NEAR);  
		
	m[0][0] = sx;	m[1][0] = 0;	m[2][0] = 0;	m[3][0] = 0;	
	m[0][1] = 0; 	m[1][1] = sy; 	m[2][1] = 0; 	m[3][1] = 0;
	m[0][2] = 0; 	m[1][2] = 0; 	m[2][2] = sz; 	m[3][2] = -1.0f;
	m[0][3] = 0; 	m[1][3] = 0; 	m[2][3] = pz; 	m[3][3] = 0;
}
