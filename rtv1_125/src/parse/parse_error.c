/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 22:14:48 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/29 15:56:55 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int		parse_error(int error)
{
	if (error == BAD_FILE)
		ft_putstr("File is not ray tracing scene description file\n");
	if (error == REPEAT_SYMBOL)
		ft_putstr("Repeat Symbol\n");
	if (error == UNEXPECTED_SYMBOL)
		ft_putstr("Unexpected Symbol\n");
	if (error == TOO_MANY_OBJECTS)
		ft_putstr("Too many objects\n");
	if (error == TOO_MANY_LIGHTS)
		ft_putstr("Too many lights\n");
	if (error == CONFLICTING_IDS)
		ft_putstr("Conflicting IDs\n");
	if (error == MEMORY_ERROR)
		ft_putstr("Malloc returned a NULL pointer\n");
	if (error == DEGENERATE_VALUE)
		ft_putstr("Degenerate value read\n");
	if (error == UNDERDETERMINED)
		ft_putstr("Not enough elements to depict");
	exit(0);
	return (0);
}

int		parse_warning(int error)
{
	if (error == CAMERA_UNDEFINED)
		ft_putstr("t_camera was not defined default position is used\n");
	if (error == NO_OBJECTS)
		ft_putstr("t_scene is empty\n");
	if (error == NO_LIGHTS)
		ft_putstr("t_scene has no lights\n");
	if (error == DENSE_SCENE)
		ft_putstr("t_scene is dense, rendering time require patience");
	return (0);
}
