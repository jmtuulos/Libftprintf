/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:40:51 by jheiskan          #+#    #+#             */
/*   Updated: 2022/05/02 13:32:43 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_ll(long long int nb)
{
	char			*new;
	int				x;
	long long int	rem;

	if (nb == 0)
		return (ft_strdup("0"));
	rem = nb;
	x = (nb < 0);
	while (rem != 0)
	{
		rem = rem / 10;
		x++;
	}
	new = ft_strnew(x);
	if (new && nb < 0)
		new[0] = '-';
	while (new && x > 0 && new[x - 1] != '-')
	{
		new[--x] = ft_abs(nb % 10) + '0';
		nb /= 10;
	}
	return (new);
}
