/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:32:00 by jheiskan          #+#    #+#             */
/*   Updated: 2022/05/04 22:01:22 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_s(t_printf *tab)
{
	int		len;
	char	*p;

	p = va_arg(tab->args, char *);
	len = 6;
	if (p)
		len = ft_strlen(p);
	if (tab->dot && tab->preci < len)
		tab->width -= tab->preci;
	else
		tab->width -= len;
	if (tab->width > 0 && !tab->dash)
		align(tab, tab->width, ' ');
	if (tab->dot && tab->preci <= len)
		len = tab->preci;
	if (!p)
		tab->b_written += write(1, "(null)", len);
	else if (p)
	{
		while (*p && len-- != 0)
			tab->b_written += write(1, &*p++, 1);
	}
	if (tab->width > 0 && tab->dash)
		align(tab, tab->width, ' ');
}
