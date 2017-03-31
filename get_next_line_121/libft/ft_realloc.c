/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 18:53:46 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/03/22 22:11:27 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	int		minsize;
	void	*newptr;

	newptr = ft_memalloc(size);
	if (newptr == NULL)
		return (NULL);
	if (ptr != NULL)
	{
		minsize = ft_strlen(ptr);
		if ((int)size < minsize)
			minsize = size;
		ft_memcpy(newptr, ptr, minsize);
		free(ptr);
	}
	return (newptr);
}
