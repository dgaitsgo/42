/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 13:24:23 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/23 04:29:51 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	draw_routine(t_scop *scop)
{
	int			i;
	t_vector	sky;

	i = 0;
	set_vector(&sky, 191, 209, 229);
	clear_open_gl(sky);
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
/*
	Debug stepthrough:
- Checked init transform is well initialised to 0 foreverthing, identity for scale
- shader uniforms conform to what in program
- their locations match from when itialised to when used 
- Confusing as fuck:
	rotation works... so the transformation matrix partialy works.
	So it must be the projection you say?
		Well, the straffe doesn't work.
	Yet
		The keys do change the value of translation
		Each cycle a new matrix is generated reflecting the changes of the translation
		The passed matrix does rotate the object
		
*/

void	setup_render(t_scop *scop)
{
	t_transform	t;

	init_transform(&t);
	set_standard_shader_uniforms(&scop->gl);
	build_transformation_matrix(scop->model.model, t);
	print_matrix(scop->camera.projection);
	print_matrix(scop->model.model);
	look_at(scop->camera.view,
			new_vector(0, 0, 0), new_vector(0, 1, 0), new_vector(0, 1, 0));
	while (1)
	{
		draw_routine(scop);
		poll_events(&scop->window, &t);
		t.rotation.y += 0.2;
		build_transformation_matrix(scop->model.model, t);
		associate_standard_uniforms(&scop->gl,
									scop->model.model,
									scop->camera.view,
									scop->camera.projection);
		SDL_GL_SwapWindow(scop->window.window);
	}
}
