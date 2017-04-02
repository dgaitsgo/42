/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:49:52 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/02 03:39:09 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		usage(void)
{
	write(1, USAGE, ft_strlen(USAGE));
}

void				load_shaders(t_gl *gl)
{
	DIR				*dir;
	struct dirent	*file;		
	int				fd;
	int				ext;

	/*Should check flags if at least one of each type of shader is present*/
	if (!(dir = opendir(SHADER_PATH)))
		exit(1);
	while ((file = readdir(dir)) != NULL)
	{
		ext = get_extension(file->d_name);
		if (ext == FRAG)
		{
			gl->curr_frag_shdr->source = file_to_string(SHADER_PATH, file->d_name);
			gl->curr_frag_shdr->previous = gl->curr_frag_shdr;
			gl->curr_frag_shdr->next = new_shader(FRAG);
			gl->curr_frag_shdr = gl->curr_frag_shdr->next;

		}
		else if (ext == VERT)
		{
			gl->curr_vert_shdr->source = file_to_string(SHADER_PATH, file->d_name);
			gl->curr_vert_shdr->previous = gl->curr_vert_shdr;
			gl->curr_vert_shdr->next = new_shader(VERT);
			gl->curr_vert_shdr = gl->curr_vert_shdr->next;
		}
	}
}

void		list_to_table(t_gl *gl, t_model *model)
{
	
}

void	fill_index_arrays(t_arry_obs *arr_groups, t_face *face, int i_group, int i_face)
{
	arr_groups[i_group].vert_index[i_face + 0] = face->v[0];
	arr_groups[i_group].vert_index[i_face + 1] = face->v[1];
	arr_groups[i_group].vert_index[i_face + 2] = face->v[2];
	arr_groups[i_group].text_index[i_face + 0] = face->t[0];
	arr_groups[i_group].text_index[i_face + 1] = face->t[1];
	arr_groups[i_group].text_index[i_face + 2] = face->t[2];
	arr_groups[i_group].norm_index[i_face + 0] = face->n[0];
	arr_groups[i_group].norm_index[i_face + 1] = face->n[1];
	arr_groups[i_group].norm_index[i_face + 2] = face->n[2];
}

void				gen_index_array(t_model *model, t_array_obs *arr_groups)
{
	t_group_lst		*group;
	t_face			*face;
	int				i_face;
	int				i_group;

	i_face = 0;
	i_group = 0;
	group = model->root_group;
	while (group != NULL)
	{
		face = group->root_face;
		while (face != NULL)
		{
			fill_index_arrays(arr_groups, face, i_group, i_face);
			face = face->next;
		}
		group = group->next;
	}	
}

void	init_array_memory(t_model *display)
{
	t_array_group	*arr_groups;
	int				i;
	
	i = 0;
	arr_groups = malloc(sizeof(t_array_group) * display.model.n_groups);
	while (i < display.model.n_groups)
	{
		
		i++;
	}
}

int			main(int argc, char **argv)
{
	t_scop	display;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 2)
			exit(1);
		display.model = init_display_mem();
		display.gl = init_gl_mem(0);
		load_shaders(display.gl);
		load_obj(display.model, fd);
		init_array_memory(display.gl.groups);
		init_window(&display.window, argv[1], 400, 400);
		init_open_gl();
		put_image(&display);
	}
	else
		usage();
	return (0);
}
