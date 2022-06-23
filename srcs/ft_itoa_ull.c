/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:53:52 by jheiskan          #+#    #+#             */
/*   Updated: 2022/05/02 13:33:23 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_ull(unsigned long long int nb, int base)
{
	char					*new;
	int						x;
	unsigned long long int	rem;

	x = 0;
	if (nb == 0)
		return (ft_strdup("0"));
	rem = nb;
	while (rem > 0)
	{
		rem = rem / base;
		x++;
	}
	new = ft_strnew(x);
	while (new && x > 0)
	{
		rem = 0;
		rem = nb % base;
		if (rem > 9)
			new[--x] = rem - 10 + 'a';
		else if (rem < 10)
			new[--x] = rem + '0';
		nb /= base;
	}
	return (new);
}
