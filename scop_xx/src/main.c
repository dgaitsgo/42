/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:49:52 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/02 05:22:20 by dgaitsgo         ###   ########.fr       */
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
	return ;
}

void	fill_index_arrays(t_array_group *arr_groups, t_face_lst *face, int i_group, int i_face)
{
	arr_groups[i_group].vert_indexes[i_face + 0] = face->v[0];
	arr_groups[i_group].vert_indexes[i_face + 1] = face->v[1];
	arr_groups[i_group].vert_indexes[i_face + 2] = face->v[2];
	arr_groups[i_group].text_indexes[i_face + 0] = face->t[0];
	arr_groups[i_group].text_indexes[i_face + 1] = face->t[1];
	arr_groups[i_group].text_indexes[i_face + 2] = face->t[2];
	arr_groups[i_group].norm_indexes[i_face + 0] = face->n[0];
	arr_groups[i_group].norm_indexes[i_face + 1] = face->n[1];
	arr_groups[i_group].norm_indexes[i_face + 2] = face->n[2];
}

void				gen_index_array(t_model *model)
{
	t_group_lst		*group;
	t_face_lst		*face;
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
			fill_index_arrays(model->arr_groups, face, i_group, i_face);
			face = face->next;
			i_face++;
		}
		i_group++;
		group = group->next;
	}	
}

void		check_indexes(t_model *model)
{
	int i_face = 0;
	int	i_group = 0;
	t_array_group *arr_groups = model->arr_groups;

	while (i_group < model->n_groups)
	{
		i_face = 0;
		while (i_face < arr_groups[i_group].n_faces)
		{
			printf("%d/%d/%d %d/%d/%d %d/%d/%d\n",
			arr_groups[i_group].vert_indexes[i_face + 0],
			arr_groups[i_group].vert_indexes[i_face + 1],
			arr_groups[i_group].vert_indexes[i_face + 2],
			arr_groups[i_group].text_indexes[i_face + 0],
			arr_groups[i_group].text_indexes[i_face + 1],
			arr_groups[i_group].text_indexes[i_face + 2],
			arr_groups[i_group].norm_indexes[i_face + 0],
			arr_groups[i_group].norm_indexes[i_face + 1],
			arr_groups[i_group].norm_indexes[i_face + 2]);
			i_face++;
		}
		i_group++;
	}
}

int			main(int argc, char **argv)
{
	t_scop	scop;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 2)
			exit(1);
		scop.model = init_model_mem();
		scop.gl = init_gl_mem();
		load_shaders(scop.gl);
		load_obj(scop.model, fd);
		printf("%d\n", scop.model->n_groups);
		init_array_memory(scop.model);
		gen_index_array(scop.model);
		//fill_model_arrays(scop.model);
		//check_indexes(scop.model);
		init_window(&scop.window, argv[1], 400, 400);
		init_open_gl();
		put_image(&scop);
	}
	else
		usage();
	return (0);
}
