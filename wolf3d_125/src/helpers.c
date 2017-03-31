/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 15:42:07 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/10/07 19:27:08 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	comb_sort(int *order, double *distance, int i, int j)
{
	int		gap;
	int		swapped;

	gap = TOTAL_SPRITES;
	swapped = 0;
	while (gap > 1 || swapped)
	{
		gap = (gap * 10) / 13;
		if (gap == 9 || gap == 10)
			gap = 11;
		if (gap < 1)
			gap = 1;
		swapped = 0;
		while (i < TOTAL_SPRITES - gap)
		{
			j = i + gap;
			if (distance[i] < distance[j])
			{
				double_swap(&distance[i], &distance[j]);
				int_swap(&order[i], &order[j]);
				swapped = 1;
			}
			i++;
		}
	}
}

void	double_swap(double *a, double *b)
{
	double c;

	c = *a;
	*a = *b;
	*b = c;
}

void	int_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

double	arc_to_radians(double degrees)
{
	double pi;

	pi = 3.14159;
	return (degrees * (pi / 180));
}

int		intify(double number)
{
	return ((int)number);
}
