#include "ft_printf.h"

int	ft_printf(const char *inp_str, ...)
{
	va_list	args;
	ssize_t	rslt;

	va_start(args, inp_str);
	rslt = ft_read(inp_str, args);
	va_end(args);
	return (rslt);
}

int	main(void)
{
	char	*p = "HELLO";
	int		result;
	int		oresult;

	printf("\n--FT_PRINTF--							--PRINTF--\n");
	result = ft_printf("\nchar: -%c-", 'c');
	printf("							");
	oresult = printf("char: -%c-\n", 'c');
	result += ft_printf("string: -%s-", "Hello World");
	printf("						");
	oresult += printf("string: -%-s-\n", "Hello World");
	result += ft_printf("pointer: -%p-", p);
	printf("					");
	oresult += printf("pointer: -%p-\n", p);
	result += ft_printf("decimal: -%d-", 12345678);
	printf("						");
	oresult += printf("decimal: -%d-\n", 12345678);
	result += ft_printf("decimal: -%d-", -12345678);
	printf("						");
	oresult += printf("decimal: -%d-\n", -12345678);
	result += ft_printf("decimal: -%d-", 0);
	printf("							");
	oresult += printf("decimal: -%d-\n", 0);
	printf("RETURN: %d							RETURN: %d\n", result, oresult);
}