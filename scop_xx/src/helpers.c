/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:49:35 by dgaitsgo          #+#    #+#             */
/*   Updated: 2017/04/02 19:54:59 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int			total_bytes = 0;

void		multi_free_4(void *addr1, void *addr2,
			void *addr3, void *addr4)
{
	free_if(addr1);
	free_if(addr2);
	free_if(addr3);
	free_if(addr4);
}

void		*if_malloc(long size, int n)
{
	void	*mem;

	total_bytes += size * n;	
//	printf("Requesting = %d\n", total_bytes);
	mem = malloc(size * n);
	if (mem != NULL)
		return (mem);
	exit (1);
	return (NULL);
}

void		free_if(void *ptr)
{
	if (ptr)
		free(ptr);
}
