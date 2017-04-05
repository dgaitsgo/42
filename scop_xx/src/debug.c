/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 01:32:49 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/05 01:33:03 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		check_groups(t_group_lst *group)
{
	int	i;

	i = 0;
	while (group != NULL)
	{
		printf("Group %d\n", i);
		printf("n normals =\t%d\n", group->n_normals);
		printf("n vertices =\t%d\n", group->n_vertices);
		printf("n text coords = %d\n", group->n_text_coords);
		i++;
		group = group->next;
	}
}