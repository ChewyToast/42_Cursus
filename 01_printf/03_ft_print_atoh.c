#include "ft_printf.h"

size_t ft_print_atoh(char *str)
{
    size_t  size;

    while (!(*str))
    {
        ft_putchar_fd("0123456789abcdef"[*str++ / 16], 1);
    }
    return 0;
}