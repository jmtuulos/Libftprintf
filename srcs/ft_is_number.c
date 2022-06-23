/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jheiskan <jheiskan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:26:42 by jheiskan          #+#    #+#             */
/*   Updated: 2022/03/28 13:48:18 by jheiskan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_number(int number)
{
	char	*str;

	str = ft_itoa(number);
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '-')
			str++;
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
