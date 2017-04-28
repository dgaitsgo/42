/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tga.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 12:17:55 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/28 14:16:09 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		about_tga(t_tga *t, FILE *f)
{
	unsigned char	trash_char;
	short int		trash_int;

	//first two bytes are id length, useless
	fread(&trash_char, sizeof(unsigned char), 1, f);
	fread(&trash_char, sizeof(unsigned char), 1, f);

	fread(&t->image_type, sizeof(unsigned char), 1, f);
	if (t->image_type != 2 && t->image_type != 3)
	{
		//ft_error : invalid_texture
		//end
		exit (1);
	}
	fread(&trash_int, sizeof(unsigned int), 1, f);
	fread(&trash_int, sizeof(unsigned int), 1, f);
	fread(&trash_char, sizeof(unsigned char), 1, f);
	fread(&trash_int, sizeof(unsigned int), 1, f);
	fread(&trash_int, sizeof(unsigned int), 1, f);

	fread(&t->width, sizeof(short int), 1, f);
	fread(&t->height, sizeof(short int), 1, f);

	fread(&t->bit_depth, sizeof(unsigned char), 1, f);
	t->color_mode = t->bit_depth / 8;

	fread(&trash_char, sizeof(unsigned char), 1, f);
	t->image_size = t->width * t->height * t->bit_depth;
}

char		*parse_tga(char *path)
{
	FILE			*f;
	char			*tga;
	t_tga			t;
	int				i;

	i = 0;
	f = fopen(path, "r");
	assert(f != NULL);
	about_tga(&t, f);
	tga = ft_memalloc(sizeof(unsigned char) * t.image_size);
	fread(tga, sizeof(unsigned char), t.image_size, f);
	return (tga);
}
