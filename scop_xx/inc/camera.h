/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 11:00:30 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/22 23:24:38 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAMERA_H
# define __CAMERA_H

# include "vector.h"
# include "matrix.h"

typedef struct
{
	t_matrix		view;
	t_matrix		projection;
	t_matrix		inverse_view_matrix;
	t_vector		origin;
	t_vector		direction;
	t_vector		eye;
	t_vector		up;
	t_vector		forward;
	t_vector		right;
	double			half_width;
	double			half_height;
	double			pixel_width;
	double			pixel_height;
}					t_camera;

void				look_at(t_matrix m,
							t_vector eye,
							t_vector center,
							t_vector up);

void				perspective_matrix(	t_matrix m,
										float fov,
										float aspect_ratio);

void				init_camera(t_camera *camera);

#endif
