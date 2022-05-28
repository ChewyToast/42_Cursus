#include "../ft_printf.h"

static int	sizeofint(unsigned int n)
{
	unsigned int	indx;
	int			size;

	indx = 0;
	size = 0;
	if (n <= 0)
	{
		indx *= 10;
		size++;
		n *= -1;
	}
	while (n > indx)
	{
		n /= 10;
		size++;
	}
	size++;
	return (size);
}

static char	*itoa_extract(unsigned int n, char *str, size_t size)
{
	int	i;

	i = size - 2;
	size--;
	if (n < 0)
	{
		n *= -1;
		*str = '-';
		i++;
	}
	while (size)
	{
		str[i] = (n % 10) + 48;
		n /= 10;
		size--;
		i--;
	}
	return (str);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char			*str;
	int				size;

	size = sizeofint(n);
	if (n < 0)
		str = (char *)ft_calloc(sizeof(char), size + 1);
	else
		str = (char *)ft_calloc(sizeof(char), size);
	if (!str)
		return (0);
	return (itoa_extract(n, str, size));
}
