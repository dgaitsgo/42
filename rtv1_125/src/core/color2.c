/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 15:04:18 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/20 15:06:20 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

void			process_color(t_vector *color)
{
	if (out_of_gamut(color))
		clamp_color(color);
	normal_to_rgb(color);
}
