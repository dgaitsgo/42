/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:34:16 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/01 15:28:26 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

/*
void render()
{
    GLuint vbo,ibo;
    GLfloat verts[8][3] = {{0.0, 0.0, 0.0},
			   {0.0, 0.0, 0.1},
			   {0.0, 0.1, 0.0},
			   {0.0, 0.1, 0.1},
			   {0.1, 0.0, 0.0},
			   {0.1, 0.0, 0.1},
			   {0.1, 0.1, 0.0},
			   {0.1, 0.1, 0.1}};
    GLubyte ind[8] = {0,3,6,9,12,15,18,21};

    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ibo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

    glBufferData(GL_ARRAY_BUFFER, 24*sizeof(GLfloat), verts, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 8*sizeof(GLubyte), ind,
		 GL_STATIC_DRAW);
 
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, sizeof(GLfloat), 0);
    glDrawElements(GL_LINE_STRIP, 8, GL_UNSIGNED_BYTE, 0);
    glDisableClientState(GL_VERTEX_ARRAY);

    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ibo);
}

GLuint setup_triangle()
{
	static const GLfloat g_vertex_buffer_data[] = {
	   -1.0f, -1.0f, 0.0f,
	   1.0f, -1.0f, 0.0f,
	   0.0f,  1.0f, 0.0f,
	};

	// This will identify our vertex buffer
	GLuint vertexbuffer;
	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &vertexbuffer);
	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
	return (vertexbuffer);
}

void			render(GLuint vertexbuffer)
{
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(
	   0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
	   3,                  // size
	   GL_FLOAT,           // type
	   GL_FALSE,           // normalized?
	   0,                  // stride
	   (void*)0            // array buffer offset
	);
	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
	glDisableVertexAttribArray(0);
}
*/


void	setup_render(void);

void			init_window(WINDOW *window, char *title, int width, int height)
{
	SDL_WIDTH = width;
	SDL_HEIGHT = height;
	SDL_DEPTH = DEFAULT_COLOR_DEPTH;
	SDL_BPL = SDL_WIDTH * (SDL_DEPTH / DEFAULT_COLOR_DEPTH / 3);
	SDL_Init(SDL_INIT_VIDEO);
	if (!window->gl_context)
		printf("Couldn't get context  SDL Error: %s\n", SDL_GetError());
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_WINDOW = SDL_CreateWindow(title, 100, 200,
	SDL_WIDTH, SDL_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	window->gl_context = SDL_GL_CreateContext(SDL_WINDOW);
	if (window->gl_context == NULL)
		printf("Couldn't get context  SDL Error: %s\n", SDL_GetError());
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
	setup_render();
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
