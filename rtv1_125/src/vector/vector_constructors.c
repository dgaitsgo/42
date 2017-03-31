/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_constructors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 21:45:32 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/20 19:25:23 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

void		set_vector(t_vector *res, double x, double y, double z)
{
	res->x = x;
	res->y = y;
	res->z = z;
}

void		copy_vector(t_vector *dst, t_vector *src)
{
	dst->x = src->x;
	dst->y = src->y;
	dst->z = src->z;
}

t_vector	*new_vector_ptr(double x, double y, double z)
{
	t_vector	*res;

	res = malloc(sizeof(t_vector));
	res->x = x;
	res->y = y;
	res->z = z;
	return (res);
}
