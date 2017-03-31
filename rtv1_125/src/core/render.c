/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 20:29:28 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/28 23:40:42 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

t_vector		*trace_container(t_ray ray, t_scene *scene,
t_vector *color, int depth)
{
	t_intersection	intersection;

	if (depth > MAX_DEPTH)
		return (color);
	intersection = intersect_scene(ray, scene);
	if (intersection.object == NULL)
	{
		set_vector(color, 0, 0, 0);
		return (color);
	}
	return (shader(intersection, scene, color, depth));
}

t_intersection	intersect_scene(t_ray ray, t_scene *scene)
{
	t_intersection		current_intersection;
	t_intersection		best_intersection;
	int					i;

	i = 0;
	reset_intersection(&best_intersection);
	while (i <= scene->n_objects)
	{
		reset_intersection(&current_intersection);
		current_intersection.id = i;
		current_intersection.object = &scene->object[i];
		if (test_intersection(scene,
		&scene->object[i], ray, &current_intersection))
		{
			if (current_intersection.distance < best_intersection.distance)
			{
				copy_intersection(&best_intersection, &current_intersection);
			}
		}
		i++;
	}
	return (best_intersection);
}

t_ray			generate_primary_ray(t_camera *camera, double x, double y)
{
	t_ray		ray;
	t_vector	view_plane_x;
	t_vector	view_plane_y;

	view_plane_x =
	vector_scale(camera->right,
	((x + 0.5) * camera->pixel_width) - camera->half_width);
	view_plane_y =
	vector_scale(camera->up,
	((y + 0.5) * camera->pixel_height) - camera->half_height);
	ray.origin = camera->origin;
	ray.direction =
	unit_vector(vector_add(camera->eye,
	vector_add(view_plane_x, view_plane_y)));
	return (ray);
}

int				render(t_window *window, t_camera *camera,
t_scene *scene, t_vector *color)
{
	t_ray				ray;
	int					y;
	int					x;

	y = 0;
	AR_INDEX = 1.0;
	while (y < scene->window.height)
	{
		x = 0;
		while (x < scene->window.width)
		{
			set_vector(color, 0, 0, 0);
			ray = generate_primary_ray(camera, x, y);
			color = trace_container(ray, scene, color, 0);
			process_color(color);
			put_pixel(window, x, y, *color);
			x++;
		}
		y++;
	}
	put_and_loop(window, scene);
	return (1);
}
