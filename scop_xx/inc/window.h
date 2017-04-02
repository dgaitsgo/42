/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:46:03 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/03/23 19:37:21 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WINDOW_H
# define __WINDOW_H

# include "/Library/Frameworks/SDL2.framework/Versions/A/Headers/SDL.h"

# define WINDOW					t_window
# define DEFAULT_WINDOW_WIDTH	800
# define DEFAULT_WINDOW_HEIGHT	400
# define DEFAULT_COLOR_DEPTH	32
# define SDL_WINDOW				window->window
# define SDL_SCREEN				window->screen
# define SDL_IMAGE				window->image
# define SDL_FRAME_BUFFER		window->frame_buffer
# define SDL_WIDTH				window->width
# define SDL_HEIGHT				window->height
# define SDL_DEPTH				window->depth
# define SDL_BPL				window->bytes_per_line
# define SDL_EVENT				window->event
# define KEY					SDL_EVENT.key.keysym.sym

typedef	struct					s_sdlwindow
{
	SDL_Window					*window;
	SDL_Surface					*screen;
	SDL_Surface					*image;
	SDL_GLContext				gl_context;
	char						*frame_buffer;
	SDL_Event					event;
	int							width;
	int							height;
	int							depth;
	int							bytes_per_line;
	int							flags;
}								t_window;

void							init_window(WINDOW *window, char *title,
									int width, int height);
void							kill_sdl(WINDOW *window);

#endif