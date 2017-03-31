/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 22:11:22 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/19 23:24:03 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	parse_camera(char **tokens, int *i, t_camera *camera, int max)
{
	if (check(tokens[*i], "}") || max == MAX_CAMERA_ELEMENTS)
	{
		check_camera_flags(camera);
		return ;
	}
	if (accept(tokens[*i], "fov", i) &&
	check_repeat(&camera->flags, FOV_DEFINED))
		parse_double_container(tokens, i, &camera->fov, range(1, 359));
	else if (accept(tokens[*i], "origin", i) &&
	check_repeat(&camera->flags, ORIGIN_DEFINED))
		parse_vector(tokens, i, &camera->origin, range(-FLT_MAX, FLT_MAX));
	else if (accept(tokens[*i], "direction", i) &&
	check_repeat(&camera->flags, DIRECTION_DEFINED))
		parse_vector(tokens, i, &camera->direction, range(-FLT_MAX, FLT_MAX));
	else if (accept(tokens[*i], "Transformation", i) &&
	check_repeat(&camera->flags, TRANSFORM_DEFINED))
		parse_transform_container(tokens, i, &camera->transformation);
	else
		parse_error(UNEXPECTED_SYMBOL);
	parse_camera(tokens, i, camera, max++);
}
