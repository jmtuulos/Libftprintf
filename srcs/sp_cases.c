/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_cases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:49:09 by jheiskan          #+#    #+#             */
/*   Updated: 2022/05/24 14:32:07 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	special_cases_di(t_printf *tab)
{
	if (tab->hh)
		return ((signed char)va_arg(tab->args, ssize_t));
	else if (tab->ll)
		return ((long long int)va_arg(tab->args, ssize_t));
	else if (tab->l)
		return ((long int)va_arg(tab->args, ssize_t));
	else if (tab->h)
		return ((short int)va_arg(tab->args, ssize_t));
	return ((int)va_arg(tab->args, ssize_t));
}

long double	special_cases_f(t_printf *tab)
{
	if (tab->cap_l)
		return ((long double)va_arg(tab->args, long double));
	return ((double)va_arg(tab->args, double));
}

size_t	special_cases_uox(t_printf *tab)
{
	if (tab->hh)
		return ((unsigned char)va_arg(tab->args, size_t));
	else if (tab->ll)
		return ((long long unsigned int)(va_arg(tab->args, size_t)));
	else if (tab->l)
		return ((long unsigned int)(va_arg(tab->args, size_t)));
	else if (tab->h)
		return ((unsigned short int)va_arg(tab->args, size_t));
	return ((unsigned int)va_arg(tab->args, size_t));
}
