#include "../ft_printf.h"

int read_input(const char *str, va_list args)
{
    while (*str)
    {
        if (*str == '%')
        {
            str++;
            if (*str == 'c')
                ft_putchar_fd(va_arg(args, int), 1);
            else if (*str == 's')
                ft_putstr_fd(va_arg(args, char*), 1);
//            if (*str == 'p')
//                ft_hex();
            else if (*str == 'd' || *str == 'i')
                ft_int(va_arg(args, int));
//            if (*str == 'i')
//            if (*str == 'u')
//            if (*str == 'x')
//            if (*str == 'X')
//            if (*str == '%')
        }
        else
            ft_putchar_fd(*str, 1);
        str++;
    }
}