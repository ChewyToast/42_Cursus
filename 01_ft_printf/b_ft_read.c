#include "ft_printf.h"

static ssize_t	check_conversion(va_list args, char compare, size_t *ln);

ssize_t	ft_read(const char *str, va_list args, size_t *ln)
{
	int	rslt;

	while (*str)
	{
		if (*str == '%')
		{
			str++;
			rslt = check_conversion(args, *str , ln);
		}
		else
			rslt = ft_putchar(*str, ln);
		if (rslt < 0)
			return (-1);
		str++;
	}
	return (0);
}

static ssize_t	check_conversion(va_list args, char compare, size_t *ln)
{
	int	rslt;

	if (compare == 'c')
		rslt = ft_putchar(va_arg(args, int), ln);
	else if (compare == 's')
		rslt = ft_putstr(va_arg(args, char *), ln);
	else if (compare == 'p')
		rslt = ft_ptoa(va_arg(args, unsigned long long int), ln);
/*	else if (compare == 'd')
	else if (compare == 'i')
	else if (compare == 'u')
	else if (compare == 'x')
	else if (compare == 'X')
	else if (compare == '%')*/
	return (rslt);
}