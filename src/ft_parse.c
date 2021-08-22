/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:29:38 by fporto            #+#    #+#             */
/*   Updated: 2021/08/21 20:37:32 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_init_flags(void)
{
	t_flags	flags;

	flags.width = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.dot = -1;
	flags.hash = 0;
	flags.space = 0;
	flags.plus = 0;
	return (flags);
}

int	ft_is_flag(char c)
{
	return ((c == '#') || (c == ' ') || (c == '+') || (c == '-') || (c == '0')
		|| (c == '.') || (c == '*'));
}

int	ft_put(char *str, int precision)
{
	int	i;

	i = 0;
	while (str[i] && i < precision)
		ft_putchar_fd(str[i++], 1);
	return (i);
}

int	ft_parse_flags(const char *temp, int i, t_flags *flags)
{
	if (!ft_is_conv(temp[i]) && !ft_is_flag(temp[i])
		&& !ft_isdigit(temp[i]))
		return (i);
	while (temp[i])
	{
		if (temp[i] == '#')
			flags->hash = 1;
		if (temp[i] == ' ' && !flags->plus)
			flags->space = 1;
		if (temp[i] == '+')
			(void)((flags->space = 0 || 1) && (flags->plus = 1 || 1));
		if (temp[i] == '0' && !flags->minus)
			flags->zero = 1;
		if (temp[i] == '-')
			ft_flag_minus(flags);
		if (temp[i] == '.')
			i = ft_flag_dot(temp, ++i, flags);
		if (ft_isdigit(temp[i]))
			ft_flag_digit(temp[i], flags);
		if (ft_is_conv(temp[i]))
			break ;
		i++;
	}
	return (i);
}

int	ft_parse_conv(const char c, t_flags *flags, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_conv_char(va_arg(args, int), flags);
	else if (c == 's')
		count += ft_conv_str(va_arg(args, char *), flags);
	else if (c == 'p')
		count += ft_conv_ptr(va_arg(args, unsigned long long), flags);
	else if (c == 'd' || c == 'i')
		count += ft_conv_int(va_arg(args, int), flags);
	else if (c == 'u')
		count += ft_conv_uint((unsigned int)va_arg(args, unsigned int), flags);
	else if (c == 'x')
		count += ft_conv_hexa(va_arg(args, unsigned int), 1, flags);
	else if (c == 'X')
		count += ft_conv_hexa(va_arg(args, unsigned int), 0, flags);
	else if (c == '%')
		count += ft_conv_percent(flags);
	return (count);
}
