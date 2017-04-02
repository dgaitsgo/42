/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:34:16 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/02 04:47:18 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	setup_render(t_scop *display);

void			init_window(WINDOW *window, char *title, int width, int height)
{
	SDL_WIDTH = width;
	SDL_HEIGHT = height;
	SDL_DEPTH = DEFAULT_COLOR_DEPTH;
	SDL_BPL = SDL_WIDTH * (SDL_DEPTH / DEFAULT_COLOR_DEPTH / 3);
	SDL_Init(SDL_INIT_VIDEO);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_WINDOW = SDL_CreateWindow(title, 100, 200,
	SDL_WIDTH, SDL_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	window->gl_context = SDL_GL_CreateContext(SDL_WINDOW);
}

void			kill_sdl(WINDOW *window)
{
	SDL_Quit();
	exit(0);
}

void			poll_events(t_scop *display)
{
	int			quit;
	WINDOW		*window;
	GLuint		vertexbuffer;

	window = &display->window;
	quit = 0;
	setup_render(display);
	while (!quit)
	{
		while (SDL_PollEvent(&SDL_EVENT))
		{
			if (SDL_EVENT.type == SDL_QUIT ||
			KEY == SDLK_ESCAPE)
			{
				quit = 1;
				kill_sdl(&display->window);
			}
			glClearColor(0.0f, 0.0f, 0.0f, 1.f);
			glClear(GL_COLOR_BUFFER_BIT);
			glDrawArrays(GL_TRIANGLES, 0, 3);
			SDL_GL_SwapWindow(SDL_WINDOW);
		}
	}
}

void			put_image(t_scop *display)
{
	t_window	*window;

	window = &display->window;
	poll_events(display);
}
