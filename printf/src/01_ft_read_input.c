#include "../ft_printf.h"

size_t read_input(const char *str, va_list args, size_t print_length)
{
    while (*str)
    {
        if (*str == '%')
        {
            str++;
            if (*str == 'c')
                print_length += ft_putchar_fd(va_arg(args, int), 1);
            else if (*str == 's')
                print_length += ft_putstr_fd(va_arg(args, char*), 1);
//            if (*str == 'p')
//                ft_hex();
            else if (*str == 'd' || *str == 'i')
                print_length += ft_int(va_arg(args, int), 0,  1);
            else if (*str == 'u')
                print_length += ft_int(0, va_arg(args, long int), 2);
//            if (*str == 'x')
//            if (*str == 'X')
            if (*str == '%')
                print_length += ft_putchar_fd(*str, 1);
        }
        else
            print_length += ft_putchar_fd(*str, 1);
        str++;
    }
    return (print_length);
}