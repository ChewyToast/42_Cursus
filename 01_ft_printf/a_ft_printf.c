#include "ft_printf.h"

int	ft_printf(const char *inp_str, ...)
{
	va_list	args;
	size_t	ln;
	ssize_t	rslt;

	ln = 0;
	va_start(args, inp_str);
	rslt = ft_read(inp_str, args, &ln);
	va_end(args);
	if (rslt < 0)
		return (rslt);
	return (ln);
}

int	main(void)
{
	void	*p;
	int		result;
	int		oresult;

	printf("\n---MY RESULTS---						---ORIGINAL RESULTS---\n");
	result = ft_printf("\nchar: -%c-", 'c');
	printf("							");
	oresult = printf("char: -%c-\n", 'c');
	result += ft_printf("string: -%s-", "Hello World");
	printf("						");
	oresult += printf("string: -%-s\n", "Hello World");
	result += ft_printf("pointer: -%p-", p);
	printf("					");
	oresult += printf("pointer: -%p-\n", p);
	printf("RETURN: %d							RETURN: %d\n", result, oresult);
}