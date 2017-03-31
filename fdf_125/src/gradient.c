/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 18:03:40 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/05/07 15:58:37 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

float		calc_x_step(float v[3], t_vertex *min, t_vertex *mid, t_vertex *max)
{
	return ((((v[1] - v[2]) * (min->pos.y - max->pos.y)) -
	((v[0] - v[2]) * (mid->pos.y - max->pos.y))));
}

float		calc_y_step(float v[3], t_vertex *min, t_vertex *mid, t_vertex *max)
{
	return ((((v[1] - v[2]) * (min->pos.x - max->pos.x)) -
	((v[0] - v[2]) * (mid->pos.x - max->pos.x))));
}

void		fill_depth_and_color(t_gradient *g, t_vertex *min, t_vertex *mid,
t_vertex *max)
{
	g->depth[0] = min->pos.z;
	g->depth[1] = mid->pos.z;
	g->depth[2] = max->pos.z;
	g->color[0] = min->col;
	g->color[1] = mid->col;
	g->color[2] = max->col;
}

t_gradient	new_gradient(t_vertex *min, t_vertex *mid, t_vertex *max)
{
	t_gradient	g;
	float		delta_x;
	float		delta_y;

	delta_x = 1.0f / (((mid->pos.x - max->pos.x) * (min->pos.y - max->pos.y) -
	(min->pos.x - max->pos.x) * (mid->pos.y - max->pos.y)));
	delta_y = -delta_x;
	g.one_over_z[0] = 1.0f / min->pos.w;
	g.one_over_z[1] = 1.0f / mid->pos.w;
	g.one_over_z[2] = 1.0f / max->pos.w;
	fill_depth_and_color(&g, min, mid, max);
	g.depth_x_step = calc_x_step(g.depth, min, mid, max) * delta_x;
	g.depth_y_step = calc_y_step(g.depth, min, mid, max) * delta_y;
	g.one_over_zx_step = calc_x_step(g.one_over_z, min, mid, max) * delta_x;
	g.one_over_zy_step = calc_y_step(g.one_over_z, min, mid, max) * delta_y;
	g.color_x_step = c_mult(v_sub(c_mult(v_sub(g.color[1], g.color[2]),
	(min->pos.y - max->pos.y)), c_mult(v_sub(g.color[0], g.color[2]),
	(mid->pos.y - max->pos.y))), delta_x);
	g.color_y_step = c_mult(v_sub(c_mult(v_sub(g.color[1], g.color[2]),
	(min->pos.x - max->pos.x)), c_mult(v_sub(g.color[0], g.color[2]),
	(mid->pos.x - max->pos.x))), delta_y);
	return (g);
}
