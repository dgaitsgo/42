/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 15:04:44 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/28 23:43:02 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"
#include "parse.h"
#include "flags.h"

void	check_camera_flags(t_camera *camera)
{
	if (!BIT_CHECK(camera->flags, ORIGIN_DEFINED))
		camera->origin = new_vector(0, 0, 0);
	if (!BIT_CHECK(camera->flags, DIRECTION_DEFINED))
		camera->direction = unit_vector(new_vector(0, 0, -1));
	if (!BIT_CHECK(camera->flags, FOV_DEFINED))
		camera->fov = FOV;
	if (!BIT_CHECK(camera->flags, TRANSFORM_DEFINED))
		camera->transformation =
	new_transformation(new_vector(1, 1, 1),
	new_vector(0, 0, 0), new_vector(0, 0, 0));
}

void	check_scene_flags(t_scene *scene)
{
	if (scene->n_objects < 0)
		parse_error(UNDERDETERMINED);
	if (!BIT_CHECK(scene->flags, CAMERA_DEFINED))
		default_camera(&scene->camera);
	if (!BIT_CHECK(scene->flags, WINDOW_DEFINED))
		default_window(&scene->window);
}

void	check_window_flags(t_window *window)
{
	if (!BIT_CHECK(window->flags, WIDTH_DEFINED))
		window->width = WIDTH;
	if (!BIT_CHECK(window->flags, HEIGHT_DEFINED))
		window->height = HEIGHT;
}

void	check_transformation_flags(t_transform *transformation)
{
	if (!BIT_CHECK(transformation->flags, SCALE_DEFINED))
		transformation->scale = new_vector(1, 1, 1);
	if (!BIT_CHECK(transformation->flags, ROTATION_DEFINED))
		transformation->rotation = new_vector(0, 0, 0);
	if (!BIT_CHECK(transformation->flags, TRANSLATION_DEFINED))
		transformation->translation = new_vector(0, 0, 0);
}

void	check_material_flags(t_material *material)
{
	if (!BIT_CHECK(material->flags, LAMBERT_DEFINED))
		material->lambert = random_double(0.4);
	if (!BIT_CHECK(material->flags, SPECULAR_DEFINED))
		material->specular = random_double(0.2);
	if (!BIT_CHECK(material->flags, AMBIENT_DEFINED))
		material->ambient = random_double(0.3);
	if (!BIT_CHECK(material->flags, REFLECTIVE_DEFINED))
		material->reflective = random_double(0.7);
	if (!BIT_CHECK(material->flags, COLOR_DEFINED))
		material->color = random_color();
	rgb_to_normal(&material->color);
}
