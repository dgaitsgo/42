/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 16:57:14 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/26 20:32:54 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

t_vector		new_color(double r, double g, double b)
{
	t_vector	c;
	double		color_scale;

	color_scale = 1.0 / 255;
	c.x = r * color_scale;
	c.y = g * color_scale;
	c.z = b * color_scale;
	return (c);
}

void			clamp_color(t_vector *color)
{
	double		over_flow;

	over_flow = largest(largest(color->x, color->y), color->z);
	*color = divide_vector(*color, over_flow);
}

void			rgb_to_normal(t_vector *color)
{
	double scale;

	scale = 1.0 / 255;
	color->x *= scale;
	color->y *= scale;
	color->z *= scale;
}

void			normal_to_rgb(t_vector *color)
{
	color->x *= 255.0;
	color->y *= 255.0;
	color->z *= 255.0;
}

int				out_of_gamut(t_vector *color)
{
	if (color->x > 1.0)
		return (1);
	if (color->y > 1.0)
		return (1);
	if (color->z > 1.0)
		return (1);
	return (0);
}
