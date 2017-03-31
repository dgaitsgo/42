/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 16:02:31 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/02/17 17:49:32 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	if (!(mem = (void *)malloc(sizeof(size_t) * size)))
		return (NULL);
	ft_memset(mem, 0, size);
	return (mem);
}
