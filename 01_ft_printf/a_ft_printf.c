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

	printf("\n--FT_PRINTF--							--PRINTF--\n\n");
	result = ft_printf("char: -%c-", 'c');
	printf("							");
	oresult = printf("char: -%c-", 'c');
	printf("\n");
	printf("RETURN: %d							RETURN: %d\n", result, oresult);
	result += ft_printf("string: -%s-", "Hello World");
	printf("						");
	oresult += printf("string: -%-s-", "Hello World");
	printf("\n");
	printf("RETURN: %d							RETURN: %d\n", result, oresult);
	result += ft_printf("pointer: -%p-", p);
	printf("					");
	oresult += printf("pointer: -%p-", p);
	printf("\n");
	printf("RETURN: %d							RETURN: %d\n", result, oresult);
	result += ft_printf("decimal: -%d-", 12345678);
	printf("						");
	oresult += printf("decimal: -%d-", 12345678);
	printf("\n");
	printf("RETURN: %d							RETURN: %d\n", result, oresult);
	result += ft_printf("decimal: -%d-", -12345678);
	printf("						");
	oresult += printf("decimal: -%d-", -12345678);
	printf("\n");
	printf("RETURN: %d							RETURN: %d\n", result, oresult);
	result += ft_printf("decimal: -%d-", 0);
	printf("							");
	oresult += printf("decimal: -%d-", 0);
	printf("\n");
	printf("RETURN: %d							RETURN: %d\n", result, oresult);
}
