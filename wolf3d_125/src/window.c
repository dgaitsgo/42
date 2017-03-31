/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 17:38:29 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/10/07 17:40:20 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	put_image(t_sdlwindow *window)
{
	SDL_BlitSurface(SDL_IMAGE, NULL, SDL_SCREEN, NULL);
	SDL_UpdateWindowSurface(SDL_WINDOW);
}
