/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 13:24:23 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/22 21:34:37 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	draw_routine(t_scop *scop)
{
	int			i;
	t_vector	sky;

	i = 0;
	set_vector(&sky, 191, 209, 229);
	clear_open_gl();
	glUseProgram(scop->gl.shdr_program);
	glBindVertexArray(scop->gl.vao);
	while (i < scop->model.n_groups)
	{
		glDrawArrays(	GL_TRIANGLES,
						0,
						scop->model.vertex_tables[i].i_pos / 3);	
		i++;
	}
}

void	poll_events(t_window *window, t_transform *t)
{
	while (SDL_PollEvent(&SDL_EVENT))
	{
		if (SDL_EVENT.type == SDL_QUIT ||
		KEY == SDLK_ESCAPE)
			kill_sdl(window);
		if (KEY == SDLK_a)
			t->translation[X] += 0.02f;
		if (KEY == SDLK_d)
			t->translation[X] -= 0.02f;
		if (KEY == SDLK_UP)
			t->translation[Y] -= 0.02f;
		if (KEY == SDLK_DOWN)
			t->translation[Y] += 0.02f;
		if (KEY == SDLK_w)
			t->translation[Z] -= 0.02f;
		if (KEY == SDLK_s)
			t->translation[Z] += 0.02f;
	}
}

void	setup_render(t_scop *scop)
{
	float		ry;
	t_transform	t;

	ry = 0.0f;
	init_transform(&t);
	set_standard_shader_uniforms(&scop->gl);
	print_matrix(t.rotation);
	printf("%f, %f, %f\n", t.translation[0], t.translation[1], t.translation[2]);
	while (1)
	{
		draw_routine(scop);
		poll_events(&scop->window, &t);
		ry += 0.02;
		rotate_y(t.rotation, ry);
		associate_standard_uniforms(&scop->gl,
									&t,
									scop->camera.perspective);
		SDL_GL_SwapWindow(scop->window.window);
	}
}
