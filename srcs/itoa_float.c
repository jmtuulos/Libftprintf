/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:48:11 by jheiskan          #+#    #+#             */
/*   Updated: 2022/05/30 15:48:19 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	round_nb(long double nb, int preci)
{
	long double		round;
	long double		digit;
	long long int	d;
	int				x;

	d = nb;
	digit = ft_abs(nb) - ft_abs(d);
	round = 0.5;
	if (nb < 0)
		round = -0.5;
	x = 0;
	while (x++ < preci)
	{
		round /= (long double)10.0;
		digit *= (long double)10.0;
		d = digit;
		digit = ft_abs(digit) - ft_abs(d);
	}
	if (preci == 0)
		digit = nb;
	if (1.0 - ft_abs(digit) < 0 + ft_abs(digit) || \
	(d % 2 != 0 && 1.0 - digit == 0 + digit))
		return (nb + round);
	return (nb);
}

char	*save_to_str(long double a_com, int preci)
{
	char			*new;
	int				x;
	int				digit;
	long double		tmp;

	x = 1;
	new = ft_strnew(preci + 1);
	while (new && x <= preci)
	{
		new[0] = '.';
		tmp = a_com * 10;
		digit = tmp;
		new[x++] = digit + '0';
		a_com = tmp - digit;
	}
	return (new);
}

char	*handle_nan_infinity(long double nb)
{
	if (nb == 1.0 / 0)
		return (ft_strdup("inf"));
	if (!(nb == nb))
		return (ft_strdup("nan"));
	return (ft_strdup("-inf"));
}

char	*ft_itoa_float(t_printf *tab, long double nb)
{
	long double		a_com;
	long long int	b_com;
	char			*new;
	int				neg_zero;

	neg_zero = nb == (0 && 1 / nb < 0);
	if (!tab->dot)
		tab->preci = 6;
	if (nb == 1.0 / 0 || nb == -1.0 / 0 || !(nb == nb))
		return (handle_nan_infinity(nb));
	nb = round_nb(nb, tab->preci);
	b_com = nb;
	new = ft_itoa_ll(b_com);
	if (!new)
		return (0);
	a_com = ft_abs(nb) - ft_abs(b_com);
	new = ft_joindel(new, save_to_str(a_com, tab->preci));
	if (new && (neg_zero || (nb < 0 && !b_com)))
		new = ft_joindel(ft_strdup("-"), new);
	return (new);
}
