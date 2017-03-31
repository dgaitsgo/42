/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:49:35 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/03/31 16:12:16 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void		multi_free_4(void *addr1, void *addr2,
			void *addr3, void *addr4)
{
	free_if(addr1);
	free_if(addr2);
	free_if(addr3);
	free_if(addr4);
}

void		free_if(void *ptr)
{
	if (ptr)
		free(ptr);
}
