/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 06:16:12 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/06/25 08:03:06 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		valid_key(int key)
{
	if (key == RIGHT_ARROW || key == LEFT_ARROW)
		return (1);
	if (key == UP_ARROW || key == DOWN_ARROW)
		return (1);
	if (key == NUM_PAD_PLUS || key == NUM_PAD_MINUS)
		return (1);
	return (0);
}
