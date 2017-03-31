/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 20:28:15 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/10/01 16:03:42 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

double			random_double(double max)
{
	double random;

	random = ((double)rand() / (double)(RAND_MAX)) * max;
	return (random);
}

int				random_int(double max)
{
	double random;

	random = ((double)rand() / (RAND_MAX)) * max;
	return ((int)random);
}

t_vector		random_color(void)
{
	return (new_color(random_int(255), random_int(255), random_int(255)));
}

t_material		random_material(void)
{
	t_material	material;

	material.lambert = random_double(0.4);
	material.specular = random_double(0.2);
	material.ambient = random_double(0.3);
	material.reflective = random_double(0.7);
	material.color = random_color();
	return (material);
}
