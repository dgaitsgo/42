/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 22:08:57 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/19 22:09:08 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int				is_space(char c)
{
	if (c == '\n' || c == ' ' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int				lower_case_letter(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int				capital_letter(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int				balancing_symbol(char c)
{
	if (c == '<' || c == '>' || c == '{' || c == '}')
		return (1);
	return (0);
}

int				is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if (c == '-')
		return (1);
	if (c == '.')
		return (1);
	return (0);
}
