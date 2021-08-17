/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:30:54 by fporto            #+#    #+#             */
/*   Updated: 2021/08/17 19:30:54 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_char(char c, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->minus)
		ft_putchar_fd(c, 1);
	count = ft_putwidth(flags->width, 1, 0);
	if (!flags->minus)
		ft_putchar_fd(c, 1);
	return (count + 1);
}
