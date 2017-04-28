/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 13:24:23 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/29 01:23:05 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	set_texture(t_gl *gl)
{
	int tex_loc = glGetUniformLocation (gl->shdr_program, "basic_texture");
	glUseProgram(gl->shdr_program);
	glUniform1i(tex_loc, 0);
}

void	draw_routine(t_scop *scop)
{
	int			i;
	t_vector	sky;

	i = 0;
	set_vector(&sky, 19, 12, 30);
	clear_open_gl(sky);
	set_texture(&scop->gl);
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

void	check_event(t_window *window, t_camera *c)
{
	float 		delta_time;
	t_fps_mouse *m;

	m = &c->fps_mouse;
	delta_time = m->time.delta;
	while (SDL_PollEvent(&SDL_EVENT))
	{
		if (SDL_EVENT.type == SDL_QUIT || KEY == SDLK_ESCAPE)
			kill_sdl(window);
		if (KEY == SDLK_w)
			c->position = 
				vector_add(c->position,
				vector_scale(c->direction, delta_time * m->speed));	
		if (KEY == SDLK_s)
			c->position =
				vector_subtract(c->position,
				vector_scale(c->direction, delta_time * m->speed));
		if (KEY == SDLK_d)
			c->position =
				vector_add(c->position,
				vector_scale(c->right, delta_time * m->speed));
		if (KEY == SDLK_a)
			c->position =
				vector_subtract(c->position,
				vector_scale(c->right, delta_time * m->speed));
	}
}

void	look_at_cont(t_camera *c, int handedness)
{
	if (handedness == LH)
		look_atLH(c->view,
				c->position,
				vector_add(c->position, c->direction),
				c->up);
	else if (handedness == RH)
		look_atRH(c->view,
				c->position,
				vector_add(c->position, c->direction),
				c->up);
}

void	center_model_in_view(t_camera *c, t_model *m)
{
	t_vector pos;
	t_vector direction;

	pos = new_vector(	m->bv.center.x,
						m->bv.center.y,
						m->bv.center.z + m->bv.diameter);
	direction = new_vector(0, 0, -1);
	set_camera(c, pos, direction, new_vector(0, 1, 0));
	look_at_cont(c, LH);
}

void	center_model(t_model *model)
{
	t_vector	center;
	float		*positions;
	int i;

	i = 0;
	center = model->bv.center;
	positions = model->vertex_tables->positions;
	while (i < model->vertex_tables->i_pos)
	{
		positions[i + 0] += 2 * center.x;
		positions[i + 1] += 2 * center.y;
		positions[i + 2] += 2 * center.z;
		i += 3;
	}
}

void	render(t_scop *scop)
{
	float		y_rotation;

	y_rotation = 0;
	build_translation_matrix(scop->model.offset,
	-scop->model.bv.center.x,
	-scop->model.bv.center.y,
	-scop->model.bv.center.z);

	// Wrap this up in a propper "setup"
	// then call mainloop - putimage makes a nice container

	set_standard_shader_uniforms(&scop->gl);
	scop->camera.fps_mouse.time.last_time = SDL_GetTicks();
	center_model_in_view(&scop->camera, &scop->model);
	reset_mouse(&scop->window);	
	while (1)
	{
		draw_routine(scop);
		y_rotation += 1;
		adjust_view(&scop->camera.fps_mouse, &scop->camera, &scop->window);
		check_event(&scop->window, &scop->camera);
		look_at_cont(&scop->camera, RH);
		build_rotation_matrix(scop->model.model, 0, y_rotation, 0);
		//build_transformation_matrix(scop->model.model, t);
		associate_standard_uniforms(&scop->gl,
									scop->model.model,
									scop->camera.view,
									scop->camera.projection);
		glUniformMatrix4fv(	scop->gl.uniform_refs[OFFSET],
							1, GL_TRUE,
							&scop->model.offset[0][0]);
		SDL_GL_SwapWindow(scop->window.window);
	}
}
