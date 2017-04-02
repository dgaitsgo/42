/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 03:36:57 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/02 03:57:32 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int			get_extension(const char *file_name)
{
	char	*file_extension;

	file_extension = ft_strrchr(file_name, '.');
	if (file_extension)
	{
		if (ft_strncmp(file_extension, ".frag", 4) == 0)
			return (FRAG);
		if (ft_strncmp(file_extension, ".vert", 4) == 0)
			return (VERT);
	}
	return (NONE);
}

char	*file_to_string(const char *path, const char *file)
{
	FILE	*fd;
	long	size;
	char	buff[512];
	char	*dst;

	sprintf(buff, "%s/%s", path, file);
	if (!(fd = fopen(buff, "r")))
		exit(1);
	fseek(fd, 0L, SEEK_END);
	size = ftell(fd);
	fseek(fd, 0, SEEK_SET);
	dst = malloc(size);
	if (dst)
	{
		fread(dst, 1, size + 1, fd);
		dst[size] = '\0';
	}
	fclose(fd);
	return (dst);
}
