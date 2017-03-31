/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 16:00:57 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/10/07 16:02:53 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

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
