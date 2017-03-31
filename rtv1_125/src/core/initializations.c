/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 18:03:18 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/29 16:07:43 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

void	initialize_intersection_fn_pointers(t_scene *scene)
{
	scene->intersect_fn_pointers[SPHERE] = intersect_sphere;
	scene->intersect_fn_pointers[PLANE] = intersect_plane;
	scene->intersect_fn_pointers[CYLINDER] = intersect_cylinder;
	scene->intersect_fn_pointers[CONE] = intersect_cone;
}

void	initialize_scene(t_scene *scene)
{
	scene->n_lights = 0;
	scene->n_objects = -1;
	scene->flags = 0;
	scene->camera.flags = 0;
	scene->window.flags = 0;
	new_blank_window(&scene->window);
	initialize_intersection_fn_pointers(scene);
}

void	initialize_window(t_window *window)
{
	window->mlx = mlx_init();
	window->left_offset = 0;
	window->right_offset = 0;
	window->inverse_aspect_ratio =
	(double)window->height / (double)window->width;
	window->window = mlx_new_window(window->mlx, window->width,
	window->height, "ray_trace");
	window->image = mlx_new_image(window->mlx,
	window->width, window->height);
	window->pixel_buffer = mlx_get_data_addr(window->image,
	(int *)&window->bits_per_pixel,
	&window->line_size, (int *)&window->endianess);
}

void	apply_camera_transform(t_camera *camera, t_transform transf)
{
	t_matrix transformation_matrix;

	build_transformation_matrix(transformation_matrix, transf);
	camera->origin = matrix_transform_point(&camera->origin,
	transformation_matrix);
	camera->direction = unit_vector(matrix_transform_direction(
	&camera->direction, transformation_matrix));
}

void	initialize_camera(t_camera *camera, t_window *window)
{
	apply_camera_transform(camera, camera->transformation);
	camera->eye =
	unit_vector(vector_subtract(camera->direction, camera->origin));
	camera->right = unit_vector(vector_cross(camera->eye, UP_VECTOR));
	camera->up = unit_vector(vector_cross(camera->right, camera->eye));
	camera->half_width = tan(degrees_to_radians(camera->fov / 2));
	camera->half_height = window->inverse_aspect_ratio * camera->half_width;
	camera->pixel_width =
	camera->half_width * 2 / (float)(window->width - 1);
	camera->pixel_height =
	camera->half_height * 2 / (float)(window->height - 1);
}
