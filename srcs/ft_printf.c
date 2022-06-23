/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:49:54 by jheiskan          #+#    #+#             */
/*   Updated: 2022/06/23 16:15:50 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ini_struct(t_printf *tab)
{
	tab->b_written = 0;
	tab->dash = 0;
	tab->hash = 0;
	tab->percent = 0;
	tab->dot = 0;
	tab->preci = 0;
	tab->sign = 0;
	tab->space = 0;
	tab->width = 0;
	tab->zero = 0;
	tab->hh = 0;
	tab->cap_l = 0;
	tab->l = 0;
	tab->ll = 0;
	tab->h = 0;
	tab->error = 0;
	tab->p_not = 0;
	tab->conversions = "udcsofuipxX%";
}

int	save_format(t_printf *tab, const char *str, int i)
{
	int	error;

	while (str[i] && !ft_strchr(tab->conversions, str[i]))
	{
		error = i;
		i = is_hs_zr(tab, str, i);
		i = is_space(tab, str, i);
		i = is_dot(tab, str, i);
		i = is_sign(tab, str, i);
		i = is_percent(tab, str, i);
		i = is_dash(tab, str, i);
		i = is_space(tab, str, i);
		i = is_width(tab, str, i);
		i = is_h(tab, str, i);
		i = is_l(tab, str, i);
		if (error == i)
		{
			tab->error = 1;
			return (i - 1);
		}
	}
	return (i);
}

t_printf	*allocate_tab(void)
{
	t_printf	*tab;

	tab = (t_printf *)malloc(sizeof(t_printf));
	if (!tab)
		exit(-1);
	return (tab);
}

int	ft_printf(const char *str_format, ...)
{
	t_printf	*tab;
	int			ret;
	int			i;

	i = 0;
	ret = 0;
	tab = allocate_tab();
	ini_struct(tab);
	va_start(tab->args, str_format);
	while (str_format[i])
	{
		if (str_format[i] == '%')
		{
			i = save_format(tab, str_format, i + 1);
			ret += print_format(tab, str_format[i]);
			ini_struct(tab);
		}
		else
			ret += write(1, &str_format[i], 1);
		if (str_format[i])
			i++;
	}
	va_end(tab->args);
	free (tab);
	return (ret);
}
