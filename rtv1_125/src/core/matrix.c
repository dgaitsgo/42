/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 18:43:31 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/29 16:02:31 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_trace.h"

void	identity_matrix(t_matrix m)
{
	int			i;
	int			j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			m[i][j] = i == j ? 1 : 0;
			j++;
		}
		i++;
	}
}

void	zero_matrix(t_matrix m)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			m[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	matrix_multiply(t_matrix res, t_matrix m1, t_matrix m2)
{
	int			row;
	int			col;
	int			inner;

	zero_matrix(res);
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
}
