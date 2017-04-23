/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 02:31:59 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/23 03:20:57 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	init_model(t_model *model)
{
	model->flags = 0;
	zero_matrix(model->model);
	model->root_group = new_group();
	model->n_groups = 1;
}
