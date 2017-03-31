/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_ops.z                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 20:20:05 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/05/04 03:28:35 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

t_vector		lerp(t_vector min, t_vector max, float lerp_per)
{
	t_vector inter;

	inter = v_add(c_mult(v_sub(max, min), lerp_per), min);
	return (inter);
}

t_vector		c_mult(t_vector r1, float c)
{
	t_vector res;

	res.x = r1.x * c;
	res.y = r1.y * c;
	res.z = r1.z * c;
	res.w = r1.w * c;
	return (res);
}

t_vector		v_add(t_vector r1, t_vector r2)
{
	t_vector res;

	res.x = r1.x + r2.x;
	res.y = r1.y + r2.y;
	res.z = r1.z + r2.z;
	res.w = r1.w + r2.w;
	return (res);
}

t_vector		c_add(t_vector r1, float c)
{
	t_vector res;

	res.x = r1.x + c;
	res.y = r1.y + c;
	res.z = r1.z + c;
	res.w = r1.w + c;
	return (res);
}

t_vector		v_sub(t_vector r1, t_vector r2)
{
	t_vector res;

	res.x = r1.x - r2.x;
	res.y = r1.y - r2.y;
	res.z = r1.z - r2.z;
	res.w = r1.w - r2.w;
	return (res);
}
