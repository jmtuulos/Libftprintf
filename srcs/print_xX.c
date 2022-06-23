/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xX.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:08:00 by jheiskan          #+#    #+#             */
/*   Updated: 2022/05/06 17:34:19 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_hash(t_printf *tab, char *s, char f)
{
	if (tab->hash && *s != '0')
	{
		if (tab->zero && !tab->dot)
		{
			print_ox_s(tab, f);
			align(tab, tab->width - 2, ' ');
		}
		else
		{
			align(tab, tab->width - 2, ' ');
			print_ox_s(tab, f);
		}
	}
	else
		align(tab, tab->width, ' ');
}

void	print_x(t_printf *tab, char *s, char f)
{
	while (*s && !tab->p_not)
	{
		if (f == 'X' && *s != '0')
			*s = (char)ft_toupper(*s);
		tab->b_written += write(1, &*s++, 1);
	}
}

void	print_xx(t_printf *tab, char f, int base)
{
	char	*s;
	char	*tmp;

	tab->error = 0;
	s = ft_itoa_ull(special_cases_uox(tab), base);
	if (!s)
		exit(-1);
	tmp = s;
	if (!tab->preci && *s == '0' && tab->dot)
		tab->p_not = 1;
	tab->preci -= ft_strlen(s);
	tab->width -= ft_strlen(s) - tab->p_not;
	if (tab->preci > 0)
		tab->width -= tab->preci;
	if (tab->width > 0 && !tab->dash)
		handle_hash(tab, s, f);
	else if (tab->hash && *s != '0')
		print_ox_s(tab, f);
	if (tab->preci > 0)
		align(tab, tab->preci, '0');
	print_x(tab, s, f);
	if (tab->width > 0 && tab->dash)
		align(tab, tab->width - (2 * tab->hash), ' ');
	free (tmp);
}
