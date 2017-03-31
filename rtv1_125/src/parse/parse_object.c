/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 22:16:24 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/28 23:40:55 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		max_elements(int type)
{
	if (type == PLANE)
		return (MAX_PLANE_ELEMENTS);
	if (type == SPHERE)
		return (MAX_SPHERE_ELEMENTS);
	if (type == CYLINDER)
		return (MAX_CYLINDER_ELEMENTS);
	if (type == CONE)
		return (MAX_CONE_ELEMENTS);
	return (0);
}

void	parse_object(char **tokens, int *i, t_object *object, int max_depth)
{
	if (check(tokens[*i], "}") || max_depth == max_elements(object->type))
	{
		check_object_flags(object);
		build_object_matrices(object);
		return ;
	}
	if (accept(tokens[*i], "id", i) && check_repeat(&object->flags, ID_DEFINED))
		parse_int_container(tokens, i, &object->id, range(-FLT_MAX, FLT_MAX));
	else if (accept(tokens[*i], "Transformation", i) &&
	check_repeat(&object->flags, TRANSFORM_DEFINED))
		parse_transform_container(tokens, i, &object->transformation);
	else if (accept(tokens[*i], "Material", i) &&
	check_repeat(&object->flags, MATERIAL_DEFINED))
		parse_material_container(tokens, i, &object->material);
	else
		parse_error(UNEXPECTED_SYMBOL);
	parse_object(tokens, i, object, max_depth++);
}

void	*add_object(t_scene *scene, int type)
{
	scene->n_objects++;
	if (scene->n_objects == MAX_OBJECTS)
		parse_error(TOO_MANY_OBJECTS);
	else
	{
		scene->object[scene->n_objects] = new_object(type);
		return (&scene->object[scene->n_objects]);
	}
	return (NULL);
}
