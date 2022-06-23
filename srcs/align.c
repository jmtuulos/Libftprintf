/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:16:34 by jheiskan          #+#    #+#             */
/*   Updated: 2022/05/05 14:45:19 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_signs(t_printf *tab, char *s)
{
	if (tab->sign && *s != '-')
		tab->b_written += write(1, "+", 1);
	else if (*s == '-')
		tab->b_written += write(1, &*s++, 1);
	else if (tab->space)
		tab->b_written += write(1, " ", 1);
	return (s);
}

int	check_for_dot(t_printf *tab, char *s)
{
	if (tab->hash)
	{
		while (*s)
			if (*s++ == '.')
				return (1);
		tab->width--;
		return (0);
	}
	return (0);
}

char	*align_f(t_printf *tab, int len, char c, char *s)
{
	if (tab->zero && !tab->dash)
		c = '0';
	tab->b_written += len;
	while (len-- > 0)
		write(1, &c, 1);
	return (s);
}

void	align(t_printf *tab, int len, char c)
{
	if (tab->zero && !tab->dash && !tab->dot)
		c = '0';
	tab->b_written += len;
	while (len-- > 0)
		write(1, &c, 1);
}
