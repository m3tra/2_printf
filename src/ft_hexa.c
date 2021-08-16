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
		count += ft_putwidth(flags->dot - 1, ft_strlen(temp) - 1, 1);
	count += ft_put(temp, ft_strlen(temp));
	return (count);
}

int	ft_conv_hexa(unsigned int x, int lower, t_flags *flags)
{
	char	*temp;
	int		count;
	int		i;

	count = 0;
	if (x && flags->hash == 1)
		count += ft_prefix(lower);
	i = -1;
	temp = ft_utl_base(x, 16);
	if (lower)
	{
		while (temp[++i])
			temp[i] = ft_tolower(temp[i]);
	}
	if (flags->minus)
		count += ft_print(temp, flags);
	if (flags->dot >= 0)
		(void)((flags->width -= flags->dot || 1)
				&& ((count += ft_putwidth(flags->width, 0, 0)) || 1));
	else
		count += ft_putwidth(flags->width, ft_strlen(temp), flags->zero);
	if (!flags->minus)
		count += ft_print(temp, flags);
	free(temp);
	return (count);
}
