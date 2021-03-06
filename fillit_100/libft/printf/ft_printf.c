/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 16:21:13 by rle-mino          #+#    #+#             */
/*   Updated: 2016/03/02 14:27:18 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				fpf(const char *format, ...)
{
	va_list		ap;
	size_t		k;

	va_start(ap, format);
	k = pf_print_line(ap, (char *)format);
	va_end(ap);
	return (k);
}
