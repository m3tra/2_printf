#include "ft_printf.h"

static int	ft_print(char *temp, long x, int neg, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->plus && x != -2147483648 && !neg)
	{
		ft_putchar_fd('+', 1);
		count++;
	}
	if (flags->dot >= 0)
		count += ft_putwidth(flags->dot - 1, ft_strlen(temp) - 1, 1);
	count += ft_put(temp, ft_strlen(temp));
	return (count);
}

static int	ft_dash(long *x, int *neg, t_flags *flags)
{
	int	count;

	count = 0;
	*neg = 0;
	if (*x < 0 && *x != -2147483648)
	{
		*neg = 1;
		ft_putchar_fd('-', 1);
		flags->width--;
		count++;
		*x *= -1;
	}
	return (count);
}

static int	ft_dotspace(long *x, int *neg, const char *temp, t_flags *flags)
{
	int	count;

	count = 0;
	if (flags->dot >= 0 && (size_t)flags->dot < ft_strlen(temp))
		flags->dot = ft_strlen(temp);
	if (!flags->plus && flags->space > 0 && *x != -2147483648 && !*neg)
	{
		ft_putchar_fd(' ', 1);
		flags->width--;
		count++;
	}
	return (count);
}

int	ft_conv_int(long x, t_flags *flags)
{
	char	*temp;
	int		count;
	int		neg;

	count = ft_dash(&x, &neg, flags);
	if (!flags->dot && !x)
	{
		count += ft_putwidth(flags->width, 0, 0);
		return (count);
	}
	temp = ft_itoa(x);
	count += ft_dotspace(&x, &neg, temp, flags);
	if (flags->minus)
		count += ft_print(temp, x, neg, flags);
	if (flags->dot >= 0)
	{
		flags->width -= flags->dot;
		count += ft_putwidth(flags->width, 0, 0);
	}
	else
		count += ft_putwidth(flags->width, ft_strlen(temp), flags->zero);
	if (!flags->minus)
		count += ft_print(temp, x, neg, flags);
	free(temp);
	return (count);
}
