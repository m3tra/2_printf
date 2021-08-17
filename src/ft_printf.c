/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:29:49 by fporto            #+#    #+#             */
/*   Updated: 2021/08/17 19:29:49 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_conv(char c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
		|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

static int	ft_putcount(const char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_parse_temp(const char *temp, va_list args)
{
	int		i;
	int		count;
	t_flags	flags;

	i = 0;
	count = 0;
	while (temp[i])
	{
		flags = ft_init_flags();
		if (temp[i] == '%' && temp[i + 1])
		{
			i = ft_parse_flags(temp, ++i, &flags);
			if (ft_is_conv(temp[i]))
				count += ft_parse_conv(temp[i], &flags, args);
			else if (temp[i])
				count += ft_putcount(temp[i]);
		}
		else if (temp[i] != '%')
			count += ft_putcount(temp[i]);
		i++;
	}
	return (count);
}

int	ft_printf(const char *input, ...)
{
	char		*temp;
	va_list		args;
	int			count;

	if (!input)
		return (0);
	temp = ft_strdup(input);
	va_start(args, input);
	count = 0;
	count += ft_parse_temp(temp, args);
	va_end(args);
	free(temp);
	return (count);
}
