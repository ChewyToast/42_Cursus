/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 01:00:34 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/06/10 10:45:51 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static char	*ptoa_extract(unsigned long long int n, char *str, size_t size)
{
	int	i;

	i = size - 2;
	size -= 3;
	str[0] = '0';
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

ssize_t	ft_ptoa(unsigned long long int n)
{
	char	*str;
	int		size;

	size = sizeofint(n);
	str = malloc(sizeof(char) * size);
	str[size] = '\0';
	if (!str)
		return (-1);
	str = ptoa_extract(n, str, size);
	size = ft_putstr(str);
	free(str);
	return (size);
}
