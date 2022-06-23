/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_format_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:17:24 by jheiskan          #+#    #+#             */
/*   Updated: 2022/05/02 13:23:14 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_width(t_printf *tab, const char *str, int i)
{
	int		j;
	char	*numb;

	if (str[i] == '0')
		return (i);
	if (ft_isdigit(str[i]))
	{
		j = 0;
		while (ft_isdigit(str[i + j]))
			j++;
		numb = ft_strnew(j);
		if (!numb)
			exit(-1);
		ft_strncpy(numb, &str[i], j);
		tab->width = ft_atoi(numb);
		free(numb);
		return (i + j);
	}
	return (i);
}

/*
Calculate precision from the number after the . sign
*/
int	calc_preci(t_printf *tab, const char *str, int i)
{
	int		j;
	char	*precision;

	j = 0;
	while (ft_isdigit(str[j]))
	{
		j++;
		i++;
	}
	precision = ft_strsub(str, 0, j);
	if (!precision)
		exit (-1);
	tab->preci = ft_atoi(precision);
	free(precision);
	return (i);
}

int	is_hs_zr(t_printf *tab, const char *str, int i)
{
	if (str[i] == '#')
	{
		tab->hash = 1;
		i++;
	}
	if (str[i] == '0')
	{
		tab->zero = 1;
		i++;
	}
	return (i);
}

int	is_l(t_printf *tab, const char *str, int i)
{
	if (str[i] == 'l' && str[i + 1] == 'l')
	{
		tab->ll = 1;
		return (i + 2);
	}
	else if (str[i] == 'l')
	{
		tab->l = 1;
		i++;
	}
	if (str[i] == 'L')
	{
		tab->cap_l = 1;
		i++;
	}
	return (i);
}

int	is_percent(t_printf *tab, const char *str, int i)
{
	if (str[i] == '%')
		tab->percent = 1;
	return (i);
}
