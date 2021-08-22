/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:29:47 by fporto            #+#    #+#             */
/*   Updated: 2021/08/22 02:51:19 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_dash(int *neg)
{
	int	count;

	count = 0;
	if (*neg)
	{
		ft_putchar_fd('-', 1);
		count = 1;
	}
	return (count);
}

static int	ft_print(char *temp, long x, int *neg, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->plus && x != -2147483648 && (x == 0 || !*neg))
	{
		ft_putchar_fd('+', 1);
		count++;
	}
	if (flags->dot >= 0)
	{
		count += ft_putwidth(flags->dot - 1, ft_strlen(temp) - 1, 1, 0);
	}
	count += ft_put(temp, ft_strlen(temp));
	return (count);
}

static int	ft_dotspace(long x, int *neg, const char *temp, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->dot >= 0 && (size_t)flags->dot < ft_strlen(temp))
		flags->dot = ft_strlen(temp);
	if (!flags->plus && flags->space > 0 && x != -2147483648 && !*neg)
	{
		ft_putchar_fd(' ', 1);
		flags->width--;
		count++;
	}
	return (count);
}

static int	ft_minusdot(char *temp, long x, int *neg, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->minus == 1)
	{
		count += ft_dash(neg);
		count += ft_print(temp, x, neg, flags);
	}
	if (flags->dot >= 0 && (size_t)flags->dot < ft_strlen(temp))
		flags->dot = ft_strlen(temp);
	if (flags->dot >= 0)
	{
		flags->width -= flags->dot;
		count += ft_putwidth(flags->width, 0, 0, 0);
	}
	else
		count += ft_putwidth(flags->width, ft_strlen(temp), flags->zero, neg);
	return (count);
}

int	ft_conv_int(long n, t_flags *flags)
{
	char	*temp;
	int		count;
	int		neg;

	count = 0;
	if (!flags->dot && !n)
		count += ft_putwidth(flags->width, 0, 0, 0);
	if (!flags->dot && !n)
		return (count);
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n *= -1;
		flags->width--;
	}
	temp = ft_itoa(n);
	count += ft_dotspace(n, &neg, temp, flags);
	count += ft_minusdot(temp, n, &neg, flags);
	if (!flags->minus)
		count += ft_dash(&neg);
	if (!flags->minus)
		count += ft_print(temp, n, &neg, flags);
	free(temp);
	return (count);
}
