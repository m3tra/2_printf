/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:31:14 by fporto            #+#    #+#             */
/*   Updated: 2021/08/22 02:27:41 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print(char *temp, char *str, size_t len, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->dot >= 0)
	{
		count += ft_putwidth(flags->dot, len, 0, 0);
		if (temp || (!temp && flags->dot >= 6))
			count += ft_put(str, flags->dot);
	}
	else
		count += ft_put(str, len);
	return (count);
}

int	ft_conv_str(char *temp, t_flags *flags)
{
	int		count;
	size_t	len;
	char	*str;

	count = 0;
	if (!temp)
		str = "(null)";
	else
		str = temp;
	len = ft_strlen(str);
	if (flags->dot >= 0 && (size_t)flags->dot > len)
		flags->dot = len;
	if (flags->minus == 1)
		count += ft_print(temp, str, len, flags);
	if (temp && flags->dot >= 0)
		count += ft_putwidth(flags->width, flags->dot, 0, 0);
	else if (!temp && flags->dot >= 0 && flags->dot < 6)
		count += ft_putwidth(flags->width, 0, 0, 0);
	else
		count += ft_putwidth(flags->width, len, 0, 0);
	if (flags->minus == 0)
		count += ft_print(temp, str, len, flags);
	return (count);
}
