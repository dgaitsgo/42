/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 20:04:40 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/20 23:34:54 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_matrix	init_perspective(float fov, float aspect_ratio, float z_near,
float z_far)
{
	float		z_range;
	t_matrix	m;

	z_range = z_near - z_far;
	m = new_matrix();
	m[0][0] = 1.0f / (fov * aspect_ratio);
	m[0][1] = 0;
	m[0][2] = 0;
	m[0][3] = 0;
	m[1][0] = 0;
	m[1][1] = 1.0f / fov;
	m[1][2] = 0;
	m[1][3] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = (-z_near - z_far) / z_range;
	m[2][3] = 2 * z_far * z_near / z_range;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 1;
	m[3][3] = 0;
	return (m);
}

t_matrix	init_translation(float x, float y, float z)
{
	t_matrix m;

	m = new_matrix();
	m[0][0] = 1;
	m[0][1] = 0;
	m[0][2] = 0;
	m[0][3] = x;
	m[1][0] = 0;
	m[1][1] = 1;
	m[1][2] = 0;
	m[1][3] = y;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = 1;
	m[2][3] = z;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
	return (m);
}

t_matrix	init_scale(float x, float y, float z)
{
	t_matrix m;

	m = new_matrix();
	m[0][0] = x;
	m[0][1] = 0;
	m[0][2] = 0;
	m[0][3] = 0;
	m[1][0] = 0;
	m[1][1] = y;
	m[1][2] = 0;
	m[1][3] = 0;
	m[2][0] = 0;
	m[2][1] = 0;
	m[2][2] = z;
	m[2][3] = 0;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
	return (m);
}

t_matrix	init_screen_space(t_window *window)
{
	t_matrix	m;

	m = new_matrix();
	m[0][0] = (float)window->width / 2.0f;	m[0][1] = 0;								m[0][2] = 0;	m[0][3] = ((float)window->width / 2.0f) - 0.5f;
	m[1][0] = 0;							m[1][1] = -((float)window->height / 2.0f);	m[1][2] = 0;	m[1][3] = ((float)window->height / 2.0f) - 0.5f;
	m[2][0] = 0;							m[2][1] = 0;								m[2][2] = 1;
	m[2][3] = 0;
	m[3][0] = 0;
	m[3][1] = 0;
	m[3][2] = 0;
	m[3][3] = 1;
	return (m);
}

t_matrix	build_transform(t_window *window, t_trans *trans)
{
	t_matrix	projection;
	t_matrix	translation;
	t_matrix	rotation;
	t_matrix	scale;
	t_matrix	transform;

	projection = init_perspective((float)ft_calc_fov(70.0f),
	(float)window->width / (float)window->height, 0.1f, 1000.0f);
	translation = init_translation(trans->x_trad, trans->y_trad, trans->z_trad);
	rotation = init_rotation(trans->x_rot, trans->y_rot, trans->z_rot);
	scale = init_scale(trans->x_scale, trans->y_scale, trans->z_scale);
	transform = matrix_multip(matrix_multip(projection,
	matrix_multip(translation, rotation)), scale);
	free_matrix(projection);
	free_matrix(translation);
	free_matrix(rotation);
	free_matrix(scale);
	return (transform);
}
