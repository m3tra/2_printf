/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:29:31 by fporto            #+#    #+#             */
/*   Updated: 2021/08/22 02:24:51 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_prefix(int lower)
{
	if (lower)
		ft_putstr_fd("0x", 1);
	else
		ft_putstr_fd("0X", 1);
	return (2);
}

static int	ft_print(char *temp, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->dot >= 0)
		count += ft_putwidth(flags->dot - 1, ft_strlen(temp) - 1, 1, 0);
	if (flags->dot != 0)
		count += ft_put(temp, ft_strlen(temp));
	return (count);
}

static int	ft_dot(unsigned int x, int len, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->dot >= 0)
	{
		if (flags->dot > len)
			flags->width -= flags->dot;
		else if (flags->dot < len && x)
			flags->width -= len;
		count += ft_putwidth(flags->width, 0, 0, 0);
	}
	else
		count += ft_putwidth(flags->width, len, flags->zero, 0);
	return (count);
}

int	ft_conv_hexa(unsigned int x, int lower, t_flags *flags)
{
	char	*temp;
	int		count;
	int		i;
	int		len;

	count = 0;
	if (x && flags->hash == 1)
		count += ft_prefix(lower);
	i = -1;
	temp = ft_utl_base(x, 16);
	len = (int)ft_strlen(temp);
	if (lower)
		while (temp[++i])
			temp[i] = ft_tolower(temp[i]);
	if (flags->minus)
		count += ft_print(temp, flags);
	count += ft_dot(x, len, flags);
	if (!flags->minus)
		count += ft_print(temp, flags);
	free(temp);
	return (count);
}
