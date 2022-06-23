/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:12:23 by jheiskan          #+#    #+#             */
/*   Updated: 2022/02/14 17:12:49 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(t_printf *tab)
{
	char	a;

	a = va_arg(tab->args, int);
	tab->width -= 1;
	if (tab->width > 0 && !tab->dash)
		align(tab, tab->width, ' ');
	tab->b_written += write(1, &a, 1);
	if (tab->width > 0 && tab->dash)
		align(tab, tab->width, ' ');
	va_end(tab->args);
}
