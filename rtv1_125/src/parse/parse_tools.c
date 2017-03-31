/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 22:33:13 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/20 17:21:12 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int				in_comments(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '/')
		{
			if (s[i + 1])
			{
				if (s[i + 1] == '/')
				{
					return (1);
				}
			}
		}
		i++;
	}
	return (0);
}

int				only_spaces(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (!is_space(s[i]))
			return (0);
		i++;
	}
	return (1);
}
