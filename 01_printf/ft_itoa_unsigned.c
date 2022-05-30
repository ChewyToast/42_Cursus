/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:07:53 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/05/30 11:08:11 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	sizeofint(unsigned int n)
{
	unsigned int	indx;
	int				size;

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
	str = (char *)ft_calloc(sizeof(char), size);
	if (!str)
		return (0);
	return (itoa_extract(n, str, size));
}
