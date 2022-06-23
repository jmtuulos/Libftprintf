/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:13:26 by jheiskan          #+#    #+#             */
/*   Updated: 2022/05/05 14:22:10 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_f(t_printf *tab)
{
	char	*s;
	char	*tmp;
	int		dot_printed;

	s = ft_itoa_float(tab, special_cases_f(tab));
	dot_printed = 0;
	if (!s)
		exit(-1);
	tmp = s;
	dot_printed = check_for_dot(tab, s);
	tab->width -= ft_strlen(s) + ((tab->sign || tab->space) && *s != '-');
	if (tab->zero)
		s = print_signs(tab, s);
	if (!tab->dash && tab->width > 0)
		s = align_f(tab, tab->width, ' ', s);
	if (!tab->zero)
		s = print_signs(tab, s);
	while (*s)
		tab->b_written += write(1, &*s++, 1);
	if (!dot_printed && tab->hash)
		tab->b_written += write(1, ".", 1);
	if (tab->width > 0 && tab->dash)
		s = align_f(tab, tab->width, ' ', s);
	free (tmp);
}
