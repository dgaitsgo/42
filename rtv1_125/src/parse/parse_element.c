/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 22:12:23 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/29 00:29:07 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	parse_light(char **tokens, int *i, t_scene *scene)
{
	if (expect(tokens[*i], "position", i))
	{
		if (scene->n_lights > 1)
			parse_error(TOO_MANY_LIGHTS);
		parse_vector(tokens, i, &scene->light[scene->n_lights],
		range(-FLT_MAX, FLT_MAX));
		scene->n_lights++;
	}
}

int		object_element(int e)
{
	if (e == PLANE || e == SPHERE || e == CYLINDER || e == CONE)
		return (1);
	return (0);
}

void	parse_element_container(char **tokens, int *i,
t_scene *scene, int element)
{
	if (expect(tokens[*i], "{", i))
	{
		if (element == WINDOW_ELEM)
			parse_window(tokens, i, &scene->window, 0);
		if (element == CAMERA_ELEM)
			parse_camera(tokens, i, &scene->camera, 0);
		if (element == LIGHT_ELEM)
			parse_light(tokens, i, scene);
		if (object_element(element))
		{
			if (add_object(scene, element))
				parse_object(tokens, i, &scene->object[scene->n_objects], 0);
			else
				parse_error(MEMORY_ERROR);
		}
		if (expect(tokens[*i], "}", i))
			return ;
	}
	else
		parse_error(UNEXPECTED_SYMBOL);
}

int		element(char **tokens, int *i, t_scene *scene)
{
	if (tokens[*i] == NULL)
	{
		check_scene_flags(scene);
		return (1);
	}
	if (accept(tokens[*i], "Window", i) &&
	check_repeat(&scene->flags, WINDOW_DEFINED))
		parse_element_container(tokens, i, scene, WINDOW_ELEM);
	if (accept(tokens[*i], "Camera", i) &&
	check_repeat(&scene->flags, CAMERA_DEFINED))
		parse_element_container(tokens, i, scene, CAMERA_ELEM);
	else if (accept(tokens[*i], "Light", i))
		parse_element_container(tokens, i, scene, LIGHT_ELEM);
	else if (accept(tokens[*i], "Plane", i))
		parse_element_container(tokens, i, scene, PLANE);
	else if (accept(tokens[*i], "Sphere", i))
		parse_element_container(tokens, i, scene, SPHERE);
	else if (accept(tokens[*i], "Cylinder", i))
		parse_element_container(tokens, i, scene, CYLINDER);
	else if (accept(tokens[*i], "Cone", i))
		parse_element_container(tokens, i, scene, CONE);
	else
		return (parse_error(UNKNOWN_ELEMENT));
	return (element(tokens, i, scene));
}

int		parse_scene(char **tokens, t_scene *scene)
{
	int i;

	i = 0;
	if (element(tokens, &i, scene))
	{
		return (1);
	}
	return (0);
}
