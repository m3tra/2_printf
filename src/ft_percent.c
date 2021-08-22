/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 02:28:49 by fporto            #+#    #+#             */
/*   Updated: 2021/08/22 02:28:50 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print(char *str, t_flags *flags)
{
	int		count;

	count = 0;
	if (flags->dot >= 0)
	{
		count += ft_putwidth(flags->dot, 1, flags->zero, 0);
		count += ft_put(str, flags->dot);
	}
	else
		count += ft_put(str, 1);
	return (count);
}

int	ft_conv_percent(t_flags *flags)
{
	int		count;
	char	*str;

	count = 0;
	str = "%";
	if (flags->dot >= 0 && (size_t)flags->dot > 1)
		flags->dot = 1;
	if (flags->minus)
		count += ft_print(str, flags);
	if (!flags->minus)
		count += ft_print(str, flags);
	return (count);
}
