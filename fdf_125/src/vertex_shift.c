/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_shift.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 19:26:32 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/05/04 02:09:38 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"


//The problem is here:

t_vertex	transform(t_matrix m, t_vertex r)
{
	t_vertex v;

	v.pos.x = m[0][0] * r.pos.x + m[0][1] * r.pos.y + m[0][2] * r.pos.z + m[0][3] * r.pos.w;
	v.pos.y = m[1][0] * r.pos.x + m[1][1] * r.pos.y + m[1][2] * r.pos.z + m[1][3] * r.pos.w;
	v.pos.z = m[2][0] * r.pos.x + m[2][1] * r.pos.y + m[2][2] * r.pos.z + m[2][3] * r.pos.w;
	v.pos.w = m[3][0] * r.pos.x + m[3][1] * r.pos.y + m[3][2] * r.pos.z + m[3][3] * r.pos.w;
	v.col.x = (v.pos.w * .04f);
	v.col.y = (v.pos.w * .2f) + .3f;
	v.col.z = (v.pos.w * .9f);
	return (v);
}

t_vertex	perspective_divide(t_vertex v)
{
	t_vertex y;

	if (v.pos.w >= 0 && v.pos.w <= 0.00000001)
		v.pos.w += .04;
	y.pos.x = v.pos.x / v.pos.w;
	y.pos.y = v.pos.y / v.pos.w;
	y.pos.z = v.pos.z / v.pos.w;
	y.pos.w = v.pos.w;
	y.col = v.col;
	return (y);
}
