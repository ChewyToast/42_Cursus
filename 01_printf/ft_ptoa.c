#include "ft_printf.h"

static int	sizeofint(unsigned long long int n)
{
	int				size;

	size = 0;
	if (n == 0)
		size++;
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	size++;
	return (size);
}

static char	*itoa_extract(unsigned long long int n, char *str, size_t size)
{
	int	i;

	i = size - 3;
	size--;
    *str = '0';
    str[1] = 'x';
	while (size)
	{
		str[i] = ("0123456789abcdef"[n % 16]);
		n /= 16;
		size--;
		i--;
	}
	return (str);
}

size_t	ft_ptoa(unsigned long long int n, size_t *print_length)
{
	char			*str;
	int				size;

	size = sizeofint(n);
	str = (char *)ft_calloc(sizeof(char), (size + 2));
	if (!str)
		return (-1);
    str = itoa_extract(n, str, size);
    *print_length += ft_putstr_fd(str, 1);
    free(str);
	return (0);
}
