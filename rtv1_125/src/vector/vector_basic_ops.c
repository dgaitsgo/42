/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_basic_ops.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 21:46:17 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/20 19:24:11 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

t_vector		vector_const_add(t_vector a, double b)
{
	t_vector res;

	res.x = a.x + b;
	res.y = a.y + b;
	res.z = a.z + b;
	return (res);
}


t_vector		vector_add(t_vector a, t_vector b)
{
	t_vector res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	return (res);
}

t_vector		vector_subtract(t_vector a, t_vector b)
{
	t_vector res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return (res);
}

t_vector		vector_multiply(t_vector a, t_vector b)
{
	t_vector res;

	res.x = a.x * b.x;
	res.y = a.y * b.y;
	res.z = a.z * b.z;
	return (res);
}

t_vector		divide_vector(t_vector r, double c)
{
	t_vector	res;

	res.x = r.x / c;
	res.y = r.y / c;
	res.z = r.z / c;
	return (res);
}
