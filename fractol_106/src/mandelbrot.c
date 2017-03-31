/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 21:31:07 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/06/24 23:21:33 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	init_mandel(t_mandelbrot *m, t_window *window)
{
	m->zoom = 1;
	m->move_x = -0.5;
	m->move_y = 0;
	m->max_iter = 400;
	m->x = 0;
	m->y = 0;
	m->zoom_x = window->width / 2;
	m->zoom_y = window->height / 2;
}

void	iter_zero(t_mandelbrot *m)
{
	m->new_re = 0;
	m->new_im = 0;
	m->old_re = 0;
	m->old_im = 0;
	m->i = 0;
}

void	*unpack_fractal_thread_args(t_thread_args *args, int fractal_type)
{
	void *fractal;

	if (fractal_type == MANDEL)
	{
		fractal = (t_mandelbrot *)args->fractal;
		return (fractal);
	}
	return (NULL);
}

void	*mandelbrot(t_thread_args *args)
{
	t_mandelbrot	*m;
	t_mandelbrot	m_scoped;

	m = unpack_fractal_thread_args(args, MANDEL);
	m_scoped.x = args->tile.start_x;
	m_scoped.y = args->tile.start_y;
	m_scoped.max_x = args->tile.end_x;
	m_scoped.max_y = args->tile.end_y;
	m_scoped.width = m->width;
	m_scoped.height = m->height;
	m_scoped.new_re = 0;
	m_scoped.new_im = 0;
	m_scoped.zoom = m->zoom;
	m_scoped.move_x = m->move_x;
	m_scoped.move_y = m->move_y;
	m_scoped.max_iter = m->max_iter;
	m_scoped.window = m->window;

	while (m_scoped.x < m_scoped.max_x)
	{
		m_scoped.y = 0;
		while (m_scoped.y < m_scoped.max_y)
		{
			m_scoped.pr = 1.5 * (m_scoped.x - m_scoped.width / 2.0) / (0.5 * m_scoped.zoom * m_scoped.width) + m_scoped.move_x;
			m_scoped.pi = (m_scoped.y - m_scoped.height / 2) / (0.5 * m_scoped.zoom * m_scoped.height) + m_scoped.move_y;
			iter_zero(&m_scoped);
			while (m_scoped.i < m_scoped.max_iter)
			{
				m_scoped.old_re = m_scoped.new_re;
				m_scoped.old_im = m_scoped.new_im;
				m_scoped.new_re = m_scoped.old_re * m_scoped.old_re - m_scoped.old_im * m_scoped.old_im + m_scoped.pr;
				m_scoped.new_im = 2 * m_scoped.old_re * m_scoped.old_im + m_scoped.pi;
				if ((m_scoped.new_re * m_scoped.new_re + m_scoped.new_im * m_scoped.new_im) > 4)
					break ;
				m_scoped.i++;
			}
			m_scoped.color = calc_color(m_scoped.i % 256, m_scoped.old_re * 4 / m_scoped.new_re, 255 *
			(m_scoped.i < m_scoped.max_iter));
			draw_pixel(m_scoped.window, m_scoped.x, m_scoped.y, m_scoped.color);
			m_scoped.y++;
		}
		m_scoped.x++;
	}
	return (NULL);
}

void	multi_thread(t_mandelbrot *m)
{
	t_thread_args a;
	t_thread_args b;
	t_thread_args c;
	t_thread_args d;

	a.tile.start_x = 0;
	a.tile.start_y = 0;
	a.tile.end_x = 300;
	a.tile.end_y = 200;
	a.tile.function = mandelbrot;
	a.tile.arg = m;
	a.fractal = m;

	b.tile.start_x = 300;
	b.tile.start_y = 0;
	b.tile.end_x = 600;
	b.tile.end_y = 200;
	b.tile.function = mandelbrot;
	b.tile.arg = m;
	b.fractal = m;

	c.tile.start_x = 0;
	c.tile.start_y = 200;
	c.tile.end_x = 300;
	c.tile.end_y = 400;
	c.tile.function = mandelbrot;
	c.tile.arg = m;
	c.fractal = m;

	d.tile.start_x = 300;
	d.tile.start_y = 200;
	d.tile.end_x = 600;
	d.tile.end_y = 400;
	d.tile.function = mandelbrot;
	d.tile.arg = m;
	d.fractal = m;

	pthread_create(&a.tile.pthread, NULL, a.tile.function, &a);
	pthread_create(&b.tile.pthread, NULL, b.tile.function, &b);
	pthread_create(&c.tile.pthread, NULL, c.tile.function, &c);
	pthread_create(&d.tile.pthread, NULL, d.tile.function, &d);
	pthread_join(a.tile.pthread, NULL);
	pthread_join(b.tile.pthread, NULL);
	pthread_join(c.tile.pthread, NULL);
	pthread_join(d.tile.pthread, NULL);
}
