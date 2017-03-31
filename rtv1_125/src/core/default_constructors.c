/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defaultConstructors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 17:59:37 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/28 23:42:42 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

void		default_window(t_window *window)
{
	window->width = WIDTH;
	window->height = HEIGHT;
}

void		default_camera(t_camera *camera)
{
	camera->fov = FOV;
	camera->origin = new_vector(0, 0, 0);
	camera->direction = new_vector(0, 0, -1);
	camera->transformation = new_transformation(new_vector(1, 1, 1),
	new_vector(0, 0, 0), new_vector(0, 0, 0));
}
