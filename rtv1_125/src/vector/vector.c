/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 21:46:51 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/26 14:29:12 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

t_vector	vector_cross(t_vector a, t_vector b)
{
	t_vector	res;

	res.x = (a.y * b.z) - (a.z * b.y);
	res.y = (a.z * b.x) - (a.x * b.z);
	res.z = (a.x * b.y) - (a.y * b.x);
	return (res);
}

double		dot_product(t_vector a, t_vector b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

double		vector_length(t_vector a)
{
	return (sqrt(dot_product(a, a)));
}

t_vector	unit_vector(t_vector a)
{
	return (vector_scale(a, 1 / vector_length(a)));
}
