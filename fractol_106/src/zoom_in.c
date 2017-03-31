/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_in.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 23:28:47 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/06/25 07:55:31 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	zoom_in_mandel(t_mandelbrot *m)
{
	m->zoom *= 1.15;
	m->x = 0;
	m->y = 0;
	m->i = 0;
	m->new_re = 0;
	m->new_im = 0;
	m->old_re = 0;
	m->max_iter = 400;
}

void	zoom_in_julia(t_julia *j)
{
	j->zoom *= 1.15;
	j->x = 0;
	j->y = 0;
	j->i = 0;
	j->new_re = 0;
	j->new_im = 0;
	j->old_re = 0;
	j->max_iter = 400;
}

void	zoom_in_newton(t_newton *n)
{
	n->zoom *= 1.15;
	n->x = 0;
	n->y = 0;
	n->i = 0;
	n->max_iter = 50;
}
