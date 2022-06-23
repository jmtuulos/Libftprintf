/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_format.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:10:44 by jheiskan          #+#    #+#             */
/*   Updated: 2022/02/14 18:19:28 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_dot(t_printf *tab, const char *str, int i)
{
	if (str[i] == '.')
	{
		tab->dot = 1;
		i++;
		if (ft_isdigit(str[i]))
			i = calc_preci(tab, &str[i], i);
	}
	return (i);
}

int	is_space(t_printf *tab, const char *str, int i)
{
	if (str[i] == ' ')
	{
		tab->space = 1;
		i++;
	}
	return (i);
}

int	is_sign(t_printf *tab, const char *str, int i)
{
	if (str[i] == '+')
	{
		tab->sign = 1;
		i++;
	}
	return (i);
}

int	is_h(t_printf *tab, const char *str, int i)
{
	if (str[i] == 'h' && str[i + 1] == 'h')
	{
		tab->hh = 1;
		return (i + 2);
	}
	else if (str[i] == 'h')
	{
		tab->h = 1;
		i++;
	}
	return (i);
}

int	is_dash(t_printf *tab, const char *str, int i)
{
	if (str[i] == '-')
	{
		tab->dash = 1;
		i++;
	}
	return (i);
}
