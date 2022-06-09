#include "ft_printf.h"

int	ft_printf(const char *inp_str, ...)
{
	va_list	args;
	size_t	ln;
	ssize_t	rslt;

	va_start(args, inp_str);
	rslt = ft_read(inp_str, args, &ln);
	va_end(args);
	if (rslt < 0)
		return (rslt);
	return (ln);
}