/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 20:06:48 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/04/29 20:08:14 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void		free_matrix(t_matrix m)
{
	int i;

	i = 0;
	while (i < 4)
	{
		free(m[i]);
		m[i] = NULL;
		i++;
	}
	free(m);
	m = NULL;
}

t_matrix	new_matrix(void)
{
	t_matrix	m;
	int			i;
	int			j;

	i = 0;
	m = (float **)malloc(sizeof(float *) * 4);
	while (i < 4)
	{
		m[i] = (float *)malloc(sizeof(float) * 4);
		j = 0;
		while (j < 4)
		{
			m[i][j] = 0;
			j++;
		}
		i++;
	}
	return (m);
}

t_matrix	matrix_multip(t_matrix m1, t_matrix m2)
{
	t_matrix	res;
	int			col;
	int			row;
	int			inner;

	res = new_matrix();
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			inner = 0;
			while (inner < 4)
			{
				res[row][col] += m1[row][inner] * m2[inner][col];
				inner++;
			}
			col++;
		}
		row++;
	}
	return (res);
}
