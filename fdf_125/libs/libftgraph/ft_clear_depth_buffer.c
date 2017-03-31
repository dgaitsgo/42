/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_depth_buffer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 16:09:42 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/04/30 16:12:25 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_graph.h"

void		ft_clear_depth_buffer(float *z_buffer, size_t length)
{
	int i;

	i = 0;
	while ((size_t)i < length)
	{
		z_buffer[i] = FLT_MAX;
		i++;
	}
}
