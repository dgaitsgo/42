/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 11:40:23 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/28 17:37:58 by dgaitsgo         ###   ########.fr       */
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


void		next_texture(t_texture_lst *e)
{
	e->previous = e;
	e->next = new_texture();
	e = e->next;
}

//not painfully, but somewhat repetitive (see shaders):
//doesn't count

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
		if (ext == TGA) 
			parse_tga(file->d_name, texture);
		next_texture(texture);
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
}
