/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 14:56:13 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/10/08 15:44:10 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MACROS_H
# define __MACROS_H

# define SDL_WINDOW			window->window
# define SDL_SCREEN			window->screen
# define SDL_IMAGE			window->image
# define SDL_FRAME_BUFFER	window->frame_buffer
# define SDL_WIDTH			window->width
# define SDL_HEIGHT			window->height
# define SDL_DEPTH			window->depth
# define SDL_BPL			window->bytes_per_line
# define SDL_EVENT			window->event
# define TXTR				texture->wall_txtr
# define TOTAL_SPRITES		4
# define WEAPON				texture->weapons->weapon
# define STATUS				texture->weapons->status
# define FALSE				0
# define TRUE				1
# define HORIZONTAL			1
# define VERTICAL			0
# define KEY				SDL_EVENT.key.keysym.sym
# define X_MAX				24
# define Y_MAX				24
# define INITIAL_X			8
# define INITIAL_Y			12
# define MAX_TEXTURES		8
# define MAX_SPRITES		4
#endif
