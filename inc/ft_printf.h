/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:29:51 by fporto            #+#    #+#             */
/*   Updated: 2021/08/17 19:29:52 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct s_flags
{
	int		width;

	int		minus;
	int		zero;
	int		dot;

	int		hash;
	int		space;
	int		plus;
}	t_flags;

int		ft_printf(const char *input, ...);
char	*ft_uitoa(unsigned int n);
char	*ft_utl_base(unsigned long long number, int base);

int		ft_conv_char(char c, t_flags *flags);
int		ft_conv_hexa(unsigned int x, int lower, t_flags *flags);
int		ft_conv_int(long x, t_flags *flags);
int		ft_conv_ptr(unsigned long long ptr, t_flags *flags);
int		ft_conv_str(char *str, t_flags *flags);
int		ft_conv_uint(unsigned int x, t_flags *t_flags);

int		ft_is_conv(char c);
t_flags	ft_init_flags(void);
int		ft_is_flag(char c);
int		ft_put(char *str, int precision);
int		ft_parse_flags(const char *temp, int i, t_flags *flags);
int		ft_parse_conv(const char c, t_flags *flags, va_list args);
int		ft_parse_temp(const char *temp, va_list args);

int		ft_flag_dot(const char *temp, int i, t_flags *flags);
void	ft_flag_minus(t_flags *flags);
void	ft_flag_digit(char c, t_flags *flags);
t_flags	ft_flag_width(t_flags flags);
int		ft_putwidth(int width, int minus, int zero);

#endif
