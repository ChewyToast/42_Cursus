#include "../ft_printf.h"

void ft_int(int n)
{
    char	*num;
    
    num = ft_itoa(n);
    write(1, num, ft_strlen(num));
    free(num);
}