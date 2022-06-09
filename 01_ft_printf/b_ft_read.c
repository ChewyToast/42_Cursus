#include "ft_printf.h"

static ssize_t	check_conversion(va_list, char to_convert);

ssize_t	ft_read(char *str, va_list args, size_t *ln)
{
	int	rslt;

	while (*str)
	{
		if (*str == '%')
		{
			str++;
			check_conversion(args, *str, ln);
		}
		if (rslt < 0)
			return (0);
	}
}

static ssize_t	check_conversion(va_list args, char to_convert, size_t *ln)
{
	int	rslt;

	if (to_convert == 'c')
		rslt = ft_putchar(va_arg(args, int), ln);
	else if (to_convert == 's')
		rslt = ft_putstr(va_arg(args, char *), ln);
	else if (to_convert == 'p')
		rslt = ft_ptoa(va_arg(args, unsigned long long int), ln);
	else if (to_convert == 'd')
	else if (to_convert == 'i')
	else if (to_convert == 'u')
	else if (to_convert == 'x')
	else if (to_convert == 'X')
	else if (to_convert == '%')
	return (rslt);
}