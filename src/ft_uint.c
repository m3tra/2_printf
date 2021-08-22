/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:30:38 by fporto            #+#    #+#             */
/*   Updated: 2021/08/21 22:58:40 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print(char *temp, t_flags *flags)
{
	int	count;

	count = 0;
	if (temp[0] == '-')
	{
		ft_putchar_fd('-', 1);
		temp++;
		count++;
	}
	if (flags->dot >= 0)
		count += ft_putwidth(flags->dot - 1, ft_strlen(temp) - 1, 1, 0);
	count += ft_put(temp, ft_strlen(temp));
	return (count);
}

int	ft_conv_uint(unsigned int x, t_flags *flags)
{
	char	*temp;
	int		count;

	count = 0;
	if (!flags->dot && !x)
	{
		count += ft_putwidth(flags->width, 0, 0, 0);
		return (count);
	}
	temp = ft_uitoa(x);
	if (flags->dot >= 0 && (size_t)flags->dot < ft_strlen(temp))
		flags->dot = ft_strlen(temp);
	if (flags->minus)
		count += ft_print(temp, flags);
	if (flags->dot >= 0)
	{
		flags->width -= flags->dot;
		count += ft_putwidth(flags->width, 0, 0, 0);
	}
	else
		count += ft_putwidth(flags->width, ft_strlen(temp), flags->zero, 0);
	if (!flags->minus)
		count += ft_print(temp, flags);
	free(temp);
	return (count);
}
