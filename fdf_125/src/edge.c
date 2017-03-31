/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 13:59:33 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/05/07 16:22:00 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void		scan_edge(t_gradient grad, t_window *window, t_edge *a, t_edge *b)
{
	t_edge *left;
	t_edge *right;
	t_edge *temp;

	left = a;
	right = b;
	if (a->side == 1)
	{
		temp = left;
		left = right;
		right = temp;
	}
	grad.y_start = b->y_start;
	grad.y_end = b->y_end;
	while (grad.y_start < grad.y_end)
	{
		draw_scan_line(grad, window, left, right);
		step(left);
		step(right);
		grad.y_start++;
	}
}

void		step(t_edge *e)
{
	e->x += e->x_step;
	e->depth += e->depth_step;
}

t_edge		find_edge(t_gradient g, t_vertex *min, t_vertex *max, int ind)
{
	t_edge	e;
	float	y_dist;
	float	x_dist;
	float	y_pre_step;
	float	x_pre_step;

	x_dist = max->pos.x - min->pos.x;
	y_dist = max->pos.y - min->pos.y;
	e.y_start = (int)ceil(min->pos.y);
	e.y_end = (int)ceil(max->pos.y);
	e.x = (int)ceil(min->pos.x);
	y_pre_step = e.y_start - min->pos.y;
	e.x_step = (float)x_dist / (float)y_dist;
	e.x = min->pos.x + y_pre_step * e.x_step;
	x_pre_step = e.x - min->pos.x;
	e.one_over_z = g.one_over_z[ind] + g.one_over_zx_step * x_pre_step +
				g.one_over_zy_step * y_pre_step;
	e.one_over_z_step = g.one_over_zy_step + g.one_over_zx_step * e.x_step;
	e.depth = g.depth[ind] + g.depth_x_step *
	x_pre_step + g.depth_y_step * y_pre_step;
	e.depth_step = g.depth_y_step + g.depth_x_step * e.x_step;
	e.color = v_add(v_add(g.color[ind], (c_mult(g.color_y_step, y_pre_step))),
	(c_mult(g.color_x_step, x_pre_step)));
	e.color_step = v_add(g.color_y_step, (c_mult(g.color_x_step, e.x_step)));
	return (e);
}
