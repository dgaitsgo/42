/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 01:17:15 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/26 14:51:58 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

float	ft_float_abs(float f)
{
	return (f < 0 ? f * -1.0f : f);
}

int		inside_viewing_frustum(t_vertex v)
{
	return (
	ft_float_abs(v.pos.x) <= ft_float_abs(v.pos.w) &&
	ft_float_abs(v.pos.y) <= ft_float_abs(v.pos.w) &&
	ft_float_abs(v.pos.z) <= ft_float_abs(v.pos.w));
}

void	draw_triangle(t_window *window, t_vertex v1, t_vertex v2, t_vertex v3)
{
	if (!inside_viewing_frustum(v1) &&
	!inside_viewing_frustum(v2) &&
	!inside_viewing_frustum(v3))
	{
		return ;
	}
	else
		fill_triangle(window, v1, v2, v3);
}
