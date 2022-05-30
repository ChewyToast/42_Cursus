#include "ft_printf.h"

size_t  ft_puthexa(char *str)
{
	size_t	size;

	size = ft_strlen(str);
    while (!(*str))
        ft_putchar_fd(("0123456789abcdef"[*str++ / 16]), 1);
	return (size);
}