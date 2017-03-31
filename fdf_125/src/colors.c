/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 15:50:15 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/05/07 15:58:09 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void		get_color(t_vertex *a, t_vertex *b, t_vertex *c, t_trans *transf)
{
	a->col.x = transf->a_r_col;
	a->col.y = transf->a_g_col;
	a->col.z = transf->a_b_col;
	b->col.x = transf->b_r_col;
	b->col.y = transf->b_g_col;
	b->col.z = transf->b_b_col;
	c->col.x = transf->c_r_col;
	c->col.y = transf->c_g_col;
	c->col.z = transf->c_b_col;
}

t_vector	new_color_vector(float r, float g, float b, float t)
{
	t_vector v;

	v.x = r;
	v.y = g;
	v.z = b;
	v.w = t;
	return (v);
}
