#include <OpenGL/gl.h>
#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char **argv)
{
	SDL_GLContext	contexteOpenGL;
	SDL_Window*		fenetre;
	SDL_Event		evenements;
	int 			terminer = 0;
	const GLubyte* renderer;
	const GLubyte* version;

	// Vertices
	GLuint	vbo = 0;
	GLuint	vao = 0;
	GLfloat	points[] = {
		0.0f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
	};
	const char* vertex_shader =
		"#version 410\n"
		"in vec3 vp;"
		"void main () {"
		"  gl_Position = vec4 (vp, 1.0);"
		"}";

	const char* fragment_shader =
		"#version 410\n"
		"out vec4 frag_colour;"
		"void main () {"
		"  frag_colour = vec4 (0.5, 0.5, 0.5, 1.0);"
		"}";


	// Initialisation de la SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		SDL_Quit();
		return -1;
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 32);

	fenetre = SDL_CreateWindow("Test SDL 2.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	if (!(contexteOpenGL = SDL_GL_CreateContext(fenetre)))
		printf("SDL_Init failed: %s\n", SDL_GetError());

	renderer = glGetString (GL_RENDERER); /* get renderer string */
	version = glGetString (GL_VERSION); /* version as a string */

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	GLuint vs = glCreateShader (GL_VERTEX_SHADER);
	glShaderSource (vs, 1, &vertex_shader, NULL);
	glCompileShader (vs);
	GLuint fs = glCreateShader (GL_FRAGMENT_SHADER);
	glShaderSource (fs, 1, &fragment_shader, NULL);
	glCompileShader (fs);
	GLuint shader_programme = glCreateProgram ();
	glAttachShader (shader_programme, fs);
	glAttachShader (shader_programme, vs);
	glLinkProgram (shader_programme);

	if (!fenetre)
	{
		SDL_Quit();
		return (-1);
	}

	while(!terminer)
	{
		// Clear the window
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glUseProgram (shader_programme);
			glBindVertexArray (vao);
			// draw points 0-3 from the currently bound VAO with current in-use shader
			glDrawArrays (GL_TRIANGLES, 0, 3);
		// Update the window
		SDL_PollEvent(&evenements);
		SDL_GL_SwapWindow(fenetre);
		// SDL_WaitEvent(&evenements);
		if(evenements.window.event == SDL_WINDOWEVENT_CLOSE)
			terminer = 1;
	}
	SDL_GL_DeleteContext(contexteOpenGL);
	SDL_DestroyWindow(fenetre);
	SDL_Quit();
	return 0;
}
