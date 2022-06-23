/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:13:47 by jheiskan          #+#    #+#             */
/*   Updated: 2022/05/02 13:39:58 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_ox_s(t_printf *tab, char f)
{
	if (f == 'x')
		tab->b_written += write(1, "0x", 2);
	else if (f == 'X')
		tab->b_written += write(1, "0X", 2);
}

char	*conv_hash(t_printf *tab, char *str, char f)
{
	char	*tmp;

	tmp = str;
	if (tab->hash && *str != '0')
	{
		if (f == 'X')
			str = ft_joindel("0x", str);
		else if (f == 'x')
			str = ft_joindel("0x", str);
		free (tmp);
	}
	return (str);
}

void	print_percent(t_printf *tab)
{
	tab->width -= 1;
	if (tab->width > 0 && !tab->dash)
		align(tab, tab->width, ' ');
	tab->b_written += write(1, "%", 1);
	if (tab->width > 0 && tab->dash)
		align(tab, tab->width, ' ');
}

int	print_format(t_printf *tab, char f)
{
	if (tab->error)
		return (0);
	if (f == 'c')
		print_char(tab);
	if (f == '%')
		print_percent(tab);
	if (f == 'd' || f == 'i')
		print_di(tab);
	if (f == 's')
		print_s(tab);
	if (f == 'p')
		print_p(tab);
	if (f == 'u')
		print_u(tab);
	if (f == 'f')
		print_f(tab);
	if (f == 'x' || f == 'X')
		print_xx(tab, f, 16);
	if (f == 'o')
		print_o(tab, 8);
	return (tab->b_written);
}
