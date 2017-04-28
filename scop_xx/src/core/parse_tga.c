/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tga.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 12:17:55 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/29 01:23:04 by dgaitsgo         ###   ########.fr       */
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
	if (t->image_type != 2 && t->image_type != 3)
		exit (1);
	fread(&trash_int, sizeof(short int), 1, f);
	fread(&trash_int, sizeof(short int), 1, f);
	fread(&trash_char, sizeof(unsigned char), 1, f);
	fread(&trash_int, sizeof(short int), 1, f);
	fread(&trash_int, sizeof(short int), 1, f);

	fread(&t->width, sizeof(short int), 1, f);
	fread(&t->height, sizeof(short int), 1, f);
	printf("Width == %d\n", t->width);	
	printf("Height == %d\n", t->height);	

	fread(&t->bit_depth, sizeof(unsigned char), 1, f);
	t->color_mode = t->bit_depth / 8;

	printf("Color mode == %d\n", t->color_mode);	

	fread(&trash_char, sizeof(unsigned char), 1, f);
	t->image_size = t->width * t->height * t->color_mode;
}

void	parse_tga(const char *file_name, t_texture_lst *t)
{
	FILE			*f;
	char			buff[512];

	sprintf(buff, "%s%s", TEXTURE_PATH, file_name);
	f = fopen(buff, "r");
	assert(f != NULL);
	about_tga(t, f);
	t->data = ft_memalloc(sizeof(unsigned char) * t->image_size);
	if (fread(t->data, sizeof(unsigned char), t->image_size, f) != t->image_size)
		//ft_error (UNEXPECTED_EOF)
		exit (-1);
	//int	fd;

	//fd = open("test", O_RDWR | O_CREAT, S_IRUSR | S_IRGRP | S_IROTH);
	//write(fd, buff, t->image_size);	
}
