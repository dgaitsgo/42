/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 18:42:28 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/25 19:09:02 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

double		square(double n)
{
	return (n * n);
}

double		largest(double a, double b)
{
	return (a > b ? a : b);
}

double		smallest(double a, double b)
{
	return (a > b ? b : a);
}

int			solve_quadratic(t_quadratic *q)
{
	double	discriminant;
	double	e;
	double	denom;

	discriminant = (q->b * q->b) - 4.0 * q->a * q->c;
	if (discriminant < MIN_PRECISION)
		return (0);
	e = sqrt(discriminant);
	denom = 2.0 * q->a;
	q->t1 = (-q->b - e) / denom;
	q->t2 = (-q->b + e) / denom;
	if (q->t1 > q->t2)
		swap(&q->t1, &q->t2);
	if (q->t1 < MIN_PRECISION)
	{
		if (q->t2 < MIN_PRECISION)
			return (0);
		q->t1 = q->t2;
		q->t2 = -1;
		return (-1);
	}
	return (1);
}
