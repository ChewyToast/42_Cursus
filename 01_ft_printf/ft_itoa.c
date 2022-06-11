/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:59:35 by marvin            #+#    #+#             */
/*   Updated: 2022/05/26 21:42:45 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	sizeofint(long int n)
{
	int			size;

	size = 0;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		size++;
	}
	size++;
	return (size);
}

static char	*itoa_extract(long int n, char *str, ssize_t size)
{
	size -= 2;
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
	}
	while (size != -1)
	{
		str[size] = (n % 10) + 48;
		n /= 10;
		size--;
	}
	return (str);
}

ssize_t	ft_itoa(int n)
{
	char		*str;
	long int	size;

	if (n == 0)
		return (ft_putchar('0'));
	size = sizeofint((long int)n);
	str = malloc(sizeof(char) * size);
	if (!str)
		return (-1);
	str[size - 1] = '\0';
	if (n < 0)
		return ((ft_putstr(itoa_extract((long int)n, str, size)) + 1));
	return (ft_putstr(itoa_extract((long int)n, str, size)));
}
