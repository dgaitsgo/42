/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 13:24:23 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/01 20:49:18 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

float vertices[] = {
	0.0f, 0.5f,
	0.5f, -0.5f,
	-0.5f, -0.5f
};

const char *fragmentSource = "#version 400\nout vec4 outColor; void	main() { outColor = vec4(1.0, 1.0, 1.0, 1.0); }";

const char *vertexSource = "#version 400\nin vec2 position; void main(){ gl_Position = vec4(position, 0.0, 1.0); }";

void	check_shader_compile(GLuint shader_name)
{
	GLint	status;
	char	*buffer = malloc(512);

	glGetShaderiv(shader_name, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE)
	{
		glGetShaderInfoLog(shader_name, 512, NULL, buffer);
		printf("%s\n", buffer);
		//exit(1);
	}
	free(buffer);
}

void	status_gl(const char *message, int line, char *file)
{
	int	err;

	if ((err = glGetError()) != GL_NO_ERROR)
	{
		printf("Error : %d at  %d, %s\n", err, line, file);
		//exit(1);
	}
	else
		printf("Succeded : %s\n", message);
}

void	setup_render(t_scop *display)
{	
	GLuint err;

	/* Pass vertices to Graphics Card*/
	GLuint vbo;

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
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
	glBindFragDataLocation(shaderProgram, 0, "outColor");
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);
	status_gl("generated and linked nukka", __LINE__, __FILE__);

	/* Attach dem' VAOs*/
	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	status_gl("A = All them VAOs can getit", __LINE__, __FILE__);
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);	
	status_gl("B = All them VAOs can getit", __LINE__, __FILE__);
	glEnableVertexAttribArray(posAttrib);
	status_gl("C = All them VAOs can getit", __LINE__, __FILE__);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	status_gl("My shit bown", __LINE__, __FILE__);
}
