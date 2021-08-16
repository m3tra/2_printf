#include "ft_printf.h"

void	ft_flag_minus(t_flags *flags)
{
	flags->minus = 1;
	flags->zero = 0;
}

int	ft_flag_dot(const char *temp, int i, t_flags *flags)
{
	flags->dot = 0;
	while (ft_isdigit(temp[i]))
		flags->dot = flags->dot * 10 + temp[i++] - '0';
	return (i);
}

void	ft_flag_digit(char c, t_flags *flags)
{
	flags->width = flags->width * 10 + c - '0';
}

t_flags	ft_flag_width(t_flags flags)
{
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
		flags.zero = 0;
	}
	return (flags);
}

int	ft_putwidth(int width, int minus, int zero)
{
	int	count;

	count = 0;
	while (width > minus)
	{
		if (zero)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		width--;
		count++;
	}
	return (count);
}
