/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:31:14 by fporto            #+#    #+#             */
/*   Updated: 2021/08/17 19:31:15 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print(char *str, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->dot >= 0)
	{
		count += ft_putwidth(flags->dot, ft_strlen(str), 0);
		count += ft_put(str, flags->dot);
	}
	else
		count += ft_put(str, ft_strlen(str));
	return (count);
}

int	ft_conv_str(char *str, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->dot >= 0 && (size_t)flags->dot > ft_strlen(str))
		flags->dot = ft_strlen(str);
	if (flags->minus == 1)
		count += ft_print(str, flags);
	if (flags->dot >= 0)
		count += ft_putwidth(flags->width, flags->dot, 0);
	else
		count += ft_putwidth(flags->width, ft_strlen(str), 0);
	if (!flags->minus)
		count += ft_print(str, flags);
	return (count);
}
