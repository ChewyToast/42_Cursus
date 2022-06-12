/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 01:00:34 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/06/12 11:47:34 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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

static char	*ptoa_extract(unsigned long long int n, char *str, ssize_t size)
{
	ft_putchar('0');
	ft_putchar('x');
	while (--size >= 0)
	{
		str[size] = ("0123456789abcdef"[n % 16]);
		n /= 16;
	}
	return (str);
}

ssize_t	ft_ptoa(unsigned long long int n)
{
	char	*str;
	ssize_t	size;

	if (n == 0)
		return (ft_putstr("(nil)"));
	size = sizeofint(n);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (-1);
	str[size] = '\0';
	str = ptoa_extract(n, str, size);
	size = ft_putstr(str) + 2;
	free(str);
	return (size);
}
