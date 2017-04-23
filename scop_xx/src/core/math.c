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