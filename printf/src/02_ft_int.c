#include "../ft_printf.h"

size_t ft_int(int n, unsigned int n2, int method)
{
    char	*num;
    size_t  size;
    
    if (method == 1)
        num = ft_itoa(n);
    else if (method == 2)
        num = ft_itoa_unsigned(n2);
    size = ft_strlen(num);
    write(1, num, size);
    free(num);
    return (size);
}