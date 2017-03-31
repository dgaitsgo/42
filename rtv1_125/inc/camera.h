/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 21:42:52 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/20 22:22:13 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CAMERA_H
# define __CAMERA_H

# include "vector.h"
# include "transform.h"

typedef struct
{
	int				flags;
	t_transform		transformation;
	t_vector		origin;
	t_vector		direction;
	t_vector		eye;
	t_vector		up;
	t_vector		right;
	double			fov;
	double			half_width;
	double			half_height;
	double			pixel_width;
	double			pixel_height;
}					t_camera;

void				default_camera(t_camera *camera);
void				initialize_camera(t_camera *camera, t_window *window);
void				apply_camera_transform(t_camera *camera,
t_transform transf);
#endif
