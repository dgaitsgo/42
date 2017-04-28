/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tga.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 12:17:55 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/28 17:37:57 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		about_tga(t_texture_lst *t, FILE *f)
{
	unsigned char	trash_char;
	short int		trash_int;

	//first two bytes are id length, useless
	fread(&trash_char, sizeof(unsigned char), 1, f);
	fread(&trash_char, sizeof(unsigned char), 1, f);

	fread(&t->image_type, sizeof(unsigned char), 1, f);
	printf("This image type = %d\n", (int)t->image_type);
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

void	parse_tga(const char *file_name, t_texture_lst *t)
{
	FILE			*f;
	char			buff[512];

	sprintf(buff, "%s%s", TEXTURE_PATH, file_name);
	printf("BUFF = %s\n", buff);
	f = fopen(buff, "r");
	assert(f != NULL);
	printf("Obfiously here\n");
	about_tga(t, f);
	t->data = ft_memalloc(sizeof(unsigned char) * t->image_size);
	fread(t->data, sizeof(unsigned char), t->image_size, f);
}
