/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 11:00:30 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/15 12:29:40 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAMERA_H
# define __CAMERA_H

# include "vector.h"
# include "matrix.h"

typedef struct
{
	t_matrix		view_matrix;
	t_matrix		perspective;
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

#endif
