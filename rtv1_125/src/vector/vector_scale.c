/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 19:10:08 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/20 19:12:09 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

t_vector		vector_scale(t_vector a, double c)
{
	t_vector res;

	res.x = a.x * c;
	res.y = a.y * c;
	res.z = a.z * c;
	return (res);
}

t_vector		vector_inverse_scale(t_vector a, double c)
{
	t_vector	res;
	double		t;

	t = 1.0 / c;
	res.x = a.x * c;
	res.y = a.y * c;
	res.z = a.z * c;
	return (res);
}
