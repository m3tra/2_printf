/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:31:07 by fporto            #+#    #+#             */
/*   Updated: 2021/08/17 19:31:08 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_strtolower(char *temp)
{
	int	i;

	i = -1;
	while (temp[++i])
		temp[i] = ft_tolower(temp[i]);
}

static int	ft_print(char *ptr, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->space > 0)
	{
		ft_putchar_fd(' ', 1);
		count++;
	}
	count += ft_put("0x", 2);
	count += ft_put(ptr, ft_strlen(ptr));
	return (count);
}

static int	ft_nodotptr(t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->width >= 0 && flags->minus == 0)
	{
		count += ft_putwidth(flags->width - 2, 0, 0);
		count += ft_put("0x", 2);
	}
	else
	{
		count += ft_put("0x", 2);
		count += ft_putwidth(flags->width - 2, 0, 0);
	}
	return (count);
}

int	ft_conv_ptr(unsigned long long ptr, t_flags *flags)
{
	int		count;
	char	*str;

	count = 0;
	if (!flags->dot && !ptr)
		ft_nodotptr(flags);
	str = ft_utl_base(ptr, 16);
	ft_strtolower(str);
	if (flags->minus)
		count += ft_print(str, flags);
	count += ft_putwidth(flags->width, ft_strlen(str) + 2, 0);
	if (!flags->minus)
		count += ft_print(str, flags);
	free(str);
	return (count);
}
