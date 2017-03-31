/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaitsgo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 22:10:04 by dgaitsgo          #+#    #+#             */
/*   Updated: 2016/09/26 20:23:53 by dgaitsgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "flags.h"

int	check_repeat(int *flag_location, int test_flag)
{
	if (!BIT_CHECK(*flag_location, test_flag))
		BIT_SET(*flag_location, test_flag);
	else
		parse_error(REPEAT_SYMBOL);
	return (1);
}
