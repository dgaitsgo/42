/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 12:35:08 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/23 00:33:49 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

double		largest(double a, double b)
{
	return (a > b ? a : b);
}

int			sgn(int x)
{
	return ((x > 0) - (x < 0));
}

double		smallest(double a, double b)
{
	return (a > b ? b : a);
}

float	in_radians(float degrees)
{
	float pi;

	pi = 3.14159;
	return (degrees * (pi / 180));
}

float euclidean_distance3d(t_vector a, t_vector b)
{
	return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2)));
}

int		power_of_two(int x, int y)
{
	return ((x & (x - 1)) != 0 || (y & (y - 1)) != 0);
}

