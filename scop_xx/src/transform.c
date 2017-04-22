/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 11:43:48 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/22 12:46:32 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		zero_vector(float vec[3])
{
	vec[0] = 0;
	vec[1] = 0;
	vec[2] = 0;
}

void		init_transform(t_transform *t)
{
	t->scale = 1.0f;
	zero_matrix(t->rotation);
	zero_vector(t->translation);
}
