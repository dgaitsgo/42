/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_conv_ll.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-mino <rle-mino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 10:53:43 by rle-mino          #+#    #+#             */
/*   Updated: 2016/02/08 06:47:54 by rle-mino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		unsigned_prec_ll(t_struct data, unsigned long long nbr, int i)
{
	int		k;

	k = 0;
	k += put_prec_nbr(data.prec - i);
	ft_putunsigned_ll(nbr, 2);
	return (k);
}

static int		unsigned_min_ll(t_struct data, unsigned long long nbr, int i)
{
	int		j;
	int		k;

	k = 0;
	j = i;
	i = (data.flag & 8 || data.flag & 16) && !(data.flag & 2) ? 1 : 0;
	i += data.prec == j ? 1 : 0;
	if (data.prec > 0 && data.flag & 2)
		data.flag -= 2;
	while (k < data.min - (data.prec > j ? data.prec : j) - i)
		k += pf_putchar(data.flag & 2 ? '0' : ' ');
	k += put_prec_nbr(data.prec - j);
	if (data.prec != -1)
		ft_putunsigned_ll(nbr, 2);
	return (k);
}

static int		unsigned_hash_ll(t_struct data, unsigned long long nbr, int i)
{
	int		j;
	int		k;

	k = 0;
	j = i;
	k += put_prec_nbr(data.prec - j);
	if (data.prec != -1)
		ft_putunsigned_ll(nbr, 2);
	while (k < data.min + (data.flag & 1 ? 2 : 0) - j)
		k += pf_putchar(' ');
	return (k);
}

int				unsigned_conv_ll(t_struct data, unsigned long long nbr)
{
	int		i;
	int		k;

	k = 0;
	i = pf_retunsigned_ll(nbr, 2);
	if (data.prec == -1 && nbr == 0)
		i = 0;
	data.min = data.flag & 1 ? data.min - 2 : data.min;
	if (data.flag & 4 && data.min != 0)
		k = unsigned_hash_ll(data, nbr, i);
	else if (data.min != 0)
		k = unsigned_min_ll(data, nbr, i);
	else
		k = unsigned_prec_ll(data, nbr, i);
	return (k + i);
}
