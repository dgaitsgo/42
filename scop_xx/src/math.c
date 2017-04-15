/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 12:35:08 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/15 12:40:37 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

float	in_radians(float degrees)
{
	float pi;

	pi = 3.14159;
	return (degrees * (pi / 180));
}

float calc_fov(float theta)
{
	return (tan(in_radians(theta / 2.0f)));
}
