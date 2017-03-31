/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 02:29:29 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/06/24 23:28:05 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void		init_newton(t_newton *n)
{
	n->y = 0;
	n->x = 0;
	n->move_x = 0;
	n->move_y = 0;
	n->zoom = 1;
	n->max_iter = 100;
	n->c_im = 0;
	n->c_re = -1;
}

void		reset_newton(t_newton *n, int w, int h)
{
	n->i = -1;
	n->new_re = 1.5 * (n->x - w / 2) / (0.5 * n->zoom * w) + n->move_x;
	n->new_im = (n->y - h / 2) / (0.5 * n->zoom * h) + n->move_y;
	n->temp = 1.0;
}

void		newton(t_window *window, int w, int h, t_newton n)
{
	while (n.y < h)
	{
		n.x = -1;
		while (n.x++ < w)
		{
			reset_newton(&n, w, h);
			while (n.temp > 0.000001 && n.i++ < n.max_iter)
			{
				n.old_re = n.new_re;
				n.old_im = n.new_im;
				n.temp = (n.new_re * n.new_re + n.new_im * n.new_im) *
				(n.new_re * n.new_re + n.new_im * n.new_im);
				n.new_re = (2 * n.new_re * n.temp + n.new_re *
				n.new_re - n.new_im * n.new_im) / (3.0 * n.temp);
				n.new_im = (2 * n.new_im * (n.temp - n.old_re)) /
				(3.0 * n.temp);
				n.temp = (n.new_re - n.old_re) * (n.new_re - n.old_re) +
				(n.new_im - n.old_im) * (n.new_im - n.old_im);
			}
			n.color = calc_color(n.i % 256, n.temp * 13, 144 * n.old_im);
			draw_pixel(window, n.x, n.y, n.color);
		}
		n.y++;
	}
}
