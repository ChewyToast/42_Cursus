#include "ft_printf.h"

static ssize_t	sizeofint(unsigned long long int n)
{
	int	size;

	size = 0;
	while (n > 0)
	{
		n /= 16;
		size++;
	}
	return (size);
}

ssize_t	ft_10to16(unsigned int n, int mode)
{
	ssize_t	size;
	char	*num;

    if (n == 0)
		return (ft_putchar('0'));
    size = sizeofint(n);
	num = malloc(sizeof(char) * size + 1);
	if (num == NULL)
		return (-1);
    num[size--] = '\0';
	while (n)
	{
		if (!mode)
			num[size--] = ("0123456789abcdef"[n % 16]);
		else
			num[size--] = ("0123456789ABCDEF"[n % 16]);
		n /= 16;
	}
    size = ft_putstr(num);
	free(num);
	return (size);
}