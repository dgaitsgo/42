/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 13:24:23 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/15 10:06:26 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

//float vertices[] = {
//	0.0f, 0.5f, 0.0f,
//	0.5f, -0.5f, 0.0f,
//	-0.5f, -0.5f, 0.0f,
//};

const char *vertexSource =
	"#version 410\n"
	"in vec3 vp;"
	"uniform mat4 y_rotation;"
	"void main () {"
	"  gl_Position = y_rotation * vec4(vp, 1.0);"
	"}";

const char *fragmentSource =
	"#version 410\n"
	"out vec4 frag_colour;"
	"void main () {"
	"  frag_colour = vec4 (0.5, 0.0, 0.5, 1.0);"
	"}";

void	check_shader_compile(GLuint shader_name)
{
	GLint	status;
	char	*buffer = malloc(512);

	glGetShaderiv(shader_name, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE)
	{
		glGetShaderInfoLog(shader_name, 512, NULL, buffer);
		printf("%s\n", buffer);
		exit(1);
	}
	free(buffer);
}

void	status_gl(const char *message, int line, char *file)
{
	int	err;

	if ((err = glGetError()) != GL_NO_ERROR)
	{
		printf("Error : %d at  %d, %s\n", err, line, file);
		exit(1);
	}
	else
		printf("Succeded : %s\n", message);
}

void	setup_render(t_scop *display)
{	
	GLfloat 	*vertices = display->model->vertex_tables->position;
	int			n_faces = display->model->vertex_tables->i_pos;
	t_matrix	y_rotation;
	float		ry;

	ry = 0.0f;
	identity_matrix(y_rotation);
	print_matrix(y_rotation);

	GLuint err;
	GLuint vbo = 0;
	GLuint vao = 0;

	/* Gen VAOs*/
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	//glEnableVertexAttribArray(0);
	//glBindBuffer(GL_ARRAY_BUFFER, vbo);
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	status_gl("Got some vbaos", __LINE__, __FILE__);

	/* Generate VBOs */
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * n_faces, vertices, GL_STATIC_DRAW);
	status_gl("Got some vaos", __LINE__, __FILE__);

	glEnableVertexAttribArray(0);
	//glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	printf("\nHow many floats to open GL: %d\n", display->model->vertex_tables->i_pos);
	status_gl("Got some vbos", __LINE__, __FILE__);

	/* Vertex shader */	
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);
	status_gl("Vertex shadezzz", __LINE__, __FILE__);

	/* Fragment shader*/
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);
	status_gl("Fragment shadezzz", __LINE__, __FILE__);

	/* Check compile errors*/
	check_shader_compile(vertexShader);	
	check_shader_compile(fragmentShader);
	status_gl("Compile errors checked hommie", __LINE__, __FILE__);

	/* Generate and link shader program*/
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	status_gl("Linked shaders", __LINE__, __FILE__);

	/* Attach dem' VAOs*/
	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	//status_gl("A = All them VAOs can getit", __LINE__, __FILE__);
	//status_gl("C = All them VAOs can getit", __LINE__, __FILE__);
	
	GLint matrix_loc = glGetUniformLocation(shaderProgram, "y_rotation");
	printf("matrix_ref == %d\n", matrix_loc);
	status_gl("Matrix bound", __LINE__, __FILE__);

	
	int			quit;
	WINDOW		*window;
	GLuint		vertexbuffer;

	window = &display->window;
	quit = 0;
	while (!quit)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(shaderProgram);
		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, n_faces / 3);
		if ((err = glGetError()))
		{
			printf("GL %s, l: %d failed: %x\n", __func__, __LINE__, err);
			exit(-1);
		}
		while (SDL_PollEvent(&SDL_EVENT))
		{
			if (SDL_EVENT.type == SDL_QUIT ||
			KEY == SDLK_ESCAPE)
			{
				quit = 1;
				kill_sdl(&display->window);
			}
		}
		ry += 0.02;
		rotate_y(y_rotation, ry);
		glUniformMatrix4fv(matrix_loc, 1, GL_FALSE, &y_rotation[0][0]);
		SDL_GL_SwapWindow(SDL_WINDOW);
	}
}
