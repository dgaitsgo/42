/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 11:40:23 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/29 01:23:03 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_texture_lst		*new_texture(void)
{
	t_texture_lst	*t;

	t = ft_memalloc(sizeof(t_texture_lst));
	t->next = NULL;
	t->previous = NULL;
	t->data = NULL;
	return (t);
}

void		set_open_gl_texture_flags(void)
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}

void		next_texture(t_texture_lst *e)
{
	e->previous = e;
	e->next = new_texture();
	e = e->next;
}

//not painfully, but somewhat repetitive (see shaders):
//doesn't count

void		gen_and_activate_texture(t_texture_lst *t)
{
	glGenTextures(1, &t->ref);
	status_gl("Got first texture in there", __LINE__, __FILE__);
	glActiveTexture(GL_TEXTURE0);

	status_gl("Got first texture in there", __LINE__, __FILE__);
	glBindTexture(GL_TEXTURE_2D, t->ref);

	status_gl("Got first texture in there", __LINE__, __FILE__);
	//printf("%s\n", t->data);
	glTexImage2D(
		GL_TEXTURE_2D,
		0,
		GL_RGB,
		t->width,
		t->height,
		0,
		GL_RGB,
		GL_UNSIGNED_BYTE,
		t->data);
	status_gl("Got first texture in there", __LINE__, __FILE__);
	set_open_gl_texture_flags();
}

void		get_textures_from_directory(t_texture_lst *texture)
{
	DIR				*dir;
	struct dirent	*file;
	char			*ext_str;
	int				ext;

	if (!(dir = opendir(TEXTURE_PATH)))
		exit(1);
	while ((file = readdir(dir)) != NULL)
	{
		ext_str = get_extension(file->d_name);
		ext = match_extension_to_enum(ext_str);
		// Only supports TGA for now :
		if (ext != INVALID)
		{
			if (ext == TGA) 
				parse_tga(file->d_name, texture);
			
			next_texture(texture);
		}
	}
}

void		init_gl_texture_list(t_gl *gl)
{
	gl->root_texture = new_texture();
	gl->curr_texture = gl->root_texture;
}

void		load_textures(t_gl *gl)
{
	init_gl_texture_list(gl);
	get_textures_from_directory(gl->curr_texture);
	gen_and_activate_texture(gl->root_texture);
}
