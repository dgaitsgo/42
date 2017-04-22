/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 13:24:23 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/22 07:27:13 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	setup_render(t_scop *scop)
{	
	t_gl		gl;
	t_matrix	y_rotation;
	float		ry;
	GLuint		shaderProgram;
	int			n_faces = scop->model.vertex_tables[0].i_pos;
	float		translation[4];
	float		scale;	
	int			quit;
	WINDOW		*window;
	
	shaderProgram = scop->gl.shdr_program;
	status_gl("NADA", __LINE__, __FILE__);
	GLint trans_shdr_ref = glGetUniformLocation(shaderProgram, "trans");
	status_gl("Uniforms bound", __LINE__, __FILE__);
	GLint scale_shdr_ref = glGetUniformLocation(shaderProgram, "scale");
	GLint model_shdr_ref = glGetUniformLocation(shaderProgram, "y_rotation");
	GLint camera_shdr_ref = glGetUniformLocation(shaderProgram, "persp");

	gl = scop->gl;
	ry = 0.0f;

	scale = 1.0f;

	translation[0] = 0.0f;
	translation[1] = 0.0f;
	translation[2] = 0.0f;
	translation[3] = 0.0f;

	window = &scop->window;
	quit = 0;
	print_matrix(scop->camera.perspective); 
	while (!quit)
	{
		clear_open_gl();
		glUseProgram(shaderProgram);
		glBindVertexArray(gl.vao);
		glDrawArrays(GL_TRIANGLES, 0, n_faces / 3);	
		while (SDL_PollEvent(&SDL_EVENT))
		{
			if (SDL_EVENT.type == SDL_QUIT ||
			KEY == SDLK_ESCAPE)
			{
				quit = 1;
				kill_sdl(&scop->window);
			}
			if (KEY == SDLK_a)
				translation[X] += 0.02f;
			if (KEY == SDLK_d)
				translation[X] -= 0.02f;
			if (KEY == SDLK_UP)
				translation[Y] -= 0.02f;
			if (KEY == SDLK_DOWN)
				translation[Y] += 0.02f;
			if (KEY == SDLK_w)
				translation[Z] -= 0.02f;
			if (KEY == SDLK_s)
				translation[Z] += 0.02f;
			if (KEY == SDLK_o)
				scale += 0.2;
			if (KEY == SDLK_l)
				scale -= 0.2;
		}
		ry += 0.02;
		rotate_y(y_rotation, ry);
		glUniform4fv(trans_shdr_ref, 1, &translation[0]);
		glUniform1fv(scale_shdr_ref, 1, &scale);
		glUniformMatrix4fv(camera_shdr_ref, 1, GL_FALSE, &scop->camera.perspective[0][0]);
		glUniformMatrix4fv(model_shdr_ref, 1, GL_FALSE, &y_rotation[0][0]);
		SDL_GL_SwapWindow(SDL_WINDOW);
	}
}
