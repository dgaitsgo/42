/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 18:11:47 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/05/04 02:01:25 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		on_map(t_window *window, int i, int j, int index)
{
	if (i > window->width - 1 || j > window->height ||
	index > (int)malloc_size(window->pixel_buffer) ||
	index < 0 || i < 0 || j < 0)
	{
		return (0);
	}
	return (1);
}

t_scan	fetch_scan_data(t_edge *left, t_edge *right)
{
	t_scan	scan;

	scan.x_min = (int)ceil(left->x);
	scan.x_max = (int)ceil(right->x);
	scan.x_pre_step = scan.x_min - left->x;
	scan.x_dist = right->x - left->x;
	scan.one_over_zx_step = (right->one_over_z - left->one_over_z) /
	scan.x_dist;
	scan.depth_x_step = (right->depth - left->depth) / scan.x_dist;
	scan.one_over_z = left->one_over_z + scan.one_over_zx_step *
	scan.x_pre_step;
	scan.depth = left->depth + scan.depth_x_step * scan.x_pre_step;
	return (scan);
}

void	draw_scan_line(t_gradient grad, t_window *window, t_edge *l, t_edge *r)
{
	t_scan		scan;
	t_vector	color;
	int			index;
	int			i;

	scan = fetch_scan_data(l, r);
	i = scan.x_min - 1;
	color = v_sub(l->color, c_mult(grad.color_x_step, scan.x_pre_step));
	while (++i < scan.x_max)
	{
		index = ((i * window->bits_per_pixel >> 3) +
		grad.y_start * window->line_size);
		if (on_map(window, i, grad.y_start, index))
		{
			if (scan.depth < window->z_buffer[index])
			{
				window->z_buffer[index] = scan.depth;
				draw_pixel(window, i, grad.y_start, &color);
				scan.one_over_z += scan.one_over_zx_step;
				scan.depth += scan.depth_x_step;
				color = v_add(color, grad.color_x_step);
			}
		}
	}
}

void	scan_triangle(t_window *window, t_triangle *triangle)
{
	t_gradient	grad;
	t_edge		top_to_bottom;
	t_edge		top_to_middle;
	t_edge		middle_to_bottom;

	grad = new_gradient(
	&triangle->min_y_vert, &triangle->mid_y_vert, &triangle->max_y_vert);
	top_to_middle = find_edge(
	grad, &triangle->min_y_vert, &triangle->mid_y_vert, 0);
	top_to_bottom = find_edge(
	grad, &triangle->min_y_vert, &triangle->max_y_vert, 0);
	middle_to_bottom = find_edge(
	grad, &triangle->mid_y_vert, &triangle->max_y_vert, 1);
	top_to_bottom.side = triangle->side;
	scan_edge(grad, window, &top_to_bottom, &top_to_middle);
	scan_edge(grad, window, &top_to_bottom, &middle_to_bottom);
}

void	fill_triangle(t_window *window, t_vertex v1, t_vertex v2, t_vertex v3)
{
	t_matrix	screen_space;
	t_triangle	triangle;

	screen_space = init_screen_space(window);
	triangle.min_y_vert = transform(screen_space, v1);
	if (triangle.min_y_vert.pos.w < 0.1f)
		return ;
	triangle.mid_y_vert = transform(screen_space, v2);
	if (triangle.mid_y_vert.pos.w < 0.1f)
		return ;
	triangle.max_y_vert = transform(screen_space, v3);
	if (triangle.max_y_vert.pos.w < 0.1f)
		return ;
	triangle.min_y_vert = perspective_divide(triangle.min_y_vert);
	triangle.mid_y_vert = perspective_divide(triangle.mid_y_vert);
	triangle.max_y_vert = perspective_divide(triangle.max_y_vert);
	order_vertices_by_y(
	&triangle.min_y_vert, &triangle.mid_y_vert, &triangle.max_y_vert);
	triangle.side = (ft_twice_triangle_area(
	&triangle.min_y_vert, &triangle.max_y_vert,
	&triangle.mid_y_vert) >= 0);
	scan_triangle(window, &triangle);
}
