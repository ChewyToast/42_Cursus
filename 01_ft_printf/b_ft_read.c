#include "ft_printf.h"

static ssize_t	check_conversion(va_list args, char compare);

ssize_t	ft_read(const char *str, va_list args)
{
	ssize_t	rslt;
	ssize_t	tmp;

	rslt = 0;
	while (*str)
	{
		tmp = 0;
		if (*str == '%')
			tmp = check_conversion(args, *(++str));
		else
			tmp = ft_putchar(*str);
		if (tmp < 0)
			return (-1);
		str++;
		rslt += tmp;
	}
	return (rslt);
}

static ssize_t	check_conversion(va_list args, char compare)
{
	ssize_t	rslt;

	if (compare == 'c')
		rslt = ft_putchar(va_arg(args, int));
	else if (compare == 's')
		rslt = ft_putstr(va_arg(args, char *));
	else if (compare == 'p')
		rslt = ft_ptoa(va_arg(args, unsigned long long int));
	else if (compare == 'd' || compare == 'i')
		rslt = ft_itoa(va_arg(args, int));
/*	else if (compare == 'u')
	else if (compare == 'x')
	else if (compare == 'X')
	else if (compare == '%')*/
	return (rslt);
}
