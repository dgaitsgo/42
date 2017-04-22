/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:34:16 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/22 06:42:46 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	set_SDL_attributes(void)
{
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 32);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetSwapInterval(1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
						SDL_GL_CONTEXT_PROFILE_CORE);
}

void			init_window(WINDOW *window, char *title, int width, int height)
{
	SDL_WIDTH = width;
	SDL_HEIGHT = height;
	SDL_DEPTH = DEFAULT_COLOR_DEPTH;
	SDL_BPL = SDL_WIDTH * (SDL_DEPTH / DEFAULT_COLOR_DEPTH / 3);
	SDL_Init(SDL_INIT_VIDEO);
	set_SDL_attributes();
	SDL_WINDOW = SDL_CreateWindow(title, 100, 200,
	SDL_WIDTH, SDL_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	window->gl_context = SDL_GL_CreateContext(SDL_WINDOW);
	printf("%s\n", glGetString(GL_VERSION));
}

void			kill_sdl(WINDOW *window)
{
	SDL_Quit();
	exit(0);
	free(window);
}

void			put_image(t_scop *scop)
{
	setup_render(scop);
}
