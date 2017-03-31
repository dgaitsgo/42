/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mesh.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 14:00:51 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/05/08 22:18:17 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int			*meta_fdf(int *meta_data, int fd)
{
	char	*line;
	int		read;
	int		lines;

	lines = 0;
	read = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (invalid_line(line))
			exit(0);
		if (read == 0)
		{
			meta_data[0] = find_x_max(line);
			read = 1;
		}
		if (find_x_max(line) != meta_data[0])
			exit(0);
		lines++;
	}
	meta_data[1] = lines;
	if (lines == 0)
		exit(0);
	return (meta_data);
}

t_mesh		*init_fdf_mesh(t_mesh *fdf, int points)
{
	int j;

	j = 0;
	fdf = (t_mesh *)malloc(sizeof(t_mesh));
	fdf->vertex = (t_vertex **)malloc(sizeof(t_vertex *) * (points));
	while (j < points)
	{
		fdf->vertex[j] = (t_vertex *)malloc(sizeof(t_vertex));
		j++;
	}
	fdf->index_arr = malloc(sizeof(int) * (points * 10));
	ft_memset(fdf->index_arr, 0, (points * 10));
	fdf->vindexes = 0;
	fdf->findexes = -6;
	return (fdf);
}

void		insert_fdf_vertices(t_mesh *fdf, char **tokens, int lines, int i)
{
	fdf->vertex[fdf->vindexes]->pos.x = (float)i / 9.0f;
	fdf->vertex[fdf->vindexes]->pos.y = -atof(tokens[i]) / 24.0f;
	fdf->vertex[fdf->vindexes]->pos.z = (float)lines / 9.0f;
	fdf->vertex[fdf->vindexes]->pos.w = 1.0f;
	fdf->vindexes++;
}

void		insert_fdf_indexes(t_mesh *fdf, int i, int lines, int x_max)
{
	fdf->findexes += 6;
	fdf->index_arr[fdf->findexes] = i + lines * x_max;
	fdf->index_arr[fdf->findexes + 1] = i + lines * x_max + 1;
	fdf->index_arr[fdf->findexes + 2] = i + lines * x_max + x_max;
	fdf->index_arr[fdf->findexes + 3] = i + lines * x_max + x_max;
	fdf->index_arr[fdf->findexes + 4] = i + lines * x_max + x_max + 1;
	fdf->index_arr[fdf->findexes + 5] = i + lines * x_max + 1;
}

t_mesh		*load_fdf(int x_max, int z_max, int fd, int lines)
{
	t_mesh		*fdf;
	char		**tokens;
	char		*line;
	int			n;
	int			i;

	fdf = NULL;
	fdf = init_fdf_mesh(fdf, x_max * z_max);
	while (get_next_line(fd, &line) > 0)
	{
		n = tokenize(line, ' ', &tokens);
		if (n > 1 && tokens)
		{
			i = -1;
			while (++i < n)
			{
				insert_fdf_vertices(fdf, tokens, lines, i);
				if (i < x_max - 1 && lines < z_max - 1)
					insert_fdf_indexes(fdf, i, lines, x_max);
			}
		}
		lines++;
	}
	fdf->findexes += 6;
	return (fdf);
}
