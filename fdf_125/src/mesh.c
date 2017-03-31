/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 20:11:35 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/05/08 21:59:29 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int			get_extension(char *file_name)
{
	char *file_extension;

	file_extension = ft_strrchr(file_name, '.');
	if (file_extension)
	{
		if (ft_strncmp(file_extension, ".obj", 4) == 0)
		{
			return (OBJ);
		}
		if (ft_strncmp(file_extension, ".fdf", 4) == 0)
		{
			return (FDF);
		}
	}
	exit(0);
}

int			find_x_max(char *line)
{
	size_t	len;
	int		numbers;
	int		i;

	len = ft_strlen(line);
	numbers = 0;
	i = 0;
	while (i < (int)len)
	{
		if (ft_isdigit(line[i]))
		{
			numbers++;
			while (ft_isdigit(line[i]) && (i < (int)len))
				i++;
		}
		i++;
	}
	return (numbers);
}

int			*about_file(int *meta_data, int extension, const int fd)
{
	if (extension == FDF)
	{
		return (meta_fdf(meta_data, fd));
	}
	if (extension == OBJ)
	{
		return (meta_obj(meta_data, fd));
	}
	close(fd);
	return (meta_data);
}

void		fill_mesh(t_window *window, t_mesh *model, t_matrix trans,
t_trans *transf)
{
	int i;

	i = 0;
	while (i < model->findexes)
	{
		get_color(model->vertex[model->index_arr[i]],
		model->vertex[model->index_arr[i + 1]],
		model->vertex[model->index_arr[i + 2]], transf);
		draw_triangle(window,
		transform(trans, *model->vertex[model->index_arr[i]]),
		transform(trans, *model->vertex[model->index_arr[i + 1]]),
		transform(trans, *model->vertex[model->index_arr[i + 2]]));
		i += 3;
	}
}

t_mesh		*load_mesh(char *file_name)
{
	int		fd;
	int		extension;
	int		*meta_data;
	t_mesh	*model;

	model = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd < 2)
		exit(1);
	meta_data = malloc(sizeof(int) * 2);
	extension = get_extension(file_name);
	meta_data = about_file(meta_data, extension, fd);
	if (meta_data != NULL)
	{
		fd = open(file_name, O_RDONLY);
		if (extension == OBJ)
			model = load_obj(meta_data[0], meta_data[1], fd);
		if (extension == FDF)
			model = load_fdf(meta_data[0], meta_data[1], fd, 0);
		free(meta_data);
		close(fd);
		return (model);
	}
	return (NULL);
}
