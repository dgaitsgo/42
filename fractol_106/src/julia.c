/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 02:43:46 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/06/25 07:45:03 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	init_julia(t_julia *j)
{
	j->zoom = 1;
	j->move_x = 0;
	j->move_y = 0;
	j->max_iter = 100;
	j->x = 0;
	j->y = 0;
	j->c_re = -0.7;
	j->c_im = .27015;
}

void	julia(t_window *window, int w, int h, t_julia j)
{
	while (j.y < h)
	{
		j.x = 0;
		while (j.x < w)
		{
			j.new_re = 1.5 * (j.x - w / 2) / (0.5 * j.zoom * w) + j.move_x;
			j.new_im = (j.y - h / 2) / (0.5 * j.zoom * h) + j.move_y;
			j.i = 0;
			while (j.i < j.max_iter)
			{
				j.old_re = j.new_re;
				j.old_im = j.new_im;
				j.new_re = j.old_re * j.old_re - j.old_im * j.old_im + j.c_re;
				j.new_im = 2 * j.old_re * j.old_im + j.c_im;
				if ((j.new_re * j.new_re + j.new_im * j.new_im) > 4)
					break ;
				j.i++;
			}
			j.color = calc_color(j.i % 256, j.old_im * j.new_re / 3, 144 *
			(j.i < j.max_iter));
			draw_pixel(window, j.x, j.y, j.color);
			j.x++;
		}
		j.y++;
	}
}
