/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 14:08:34 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/10/07 17:13:06 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	set_color(t_color *color, int r, int g, int b)
{
	color->r = r;
	color->g = g;
	color->b = b;
}

void	draw_pixel(t_sdlwindow *window, t_color color, int x, int y)
{
	int i;

	i = (x * SDL_DEPTH >> 3) + y * SDL_BPL;
	SDL_FRAME_BUFFER[i] = color.r;
	SDL_FRAME_BUFFER[i + 1] = color.g;
	SDL_FRAME_BUFFER[i + 2] = color.b;
	SDL_FRAME_BUFFER[i + 3] = color.t;
}
