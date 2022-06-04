/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_16to10.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 22:36:42 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/06/04 02:03:55 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t		ft_16to10(int n, int mode)
{
	size_t	size;
	char	*num;

	size = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n *= -1;
	}
	while (n)
	{
		if (!mode)
			ft_putchar_fd("0123456789abcdef"[n % 16], 1);
		else
			ft_putchar_fd("0123456789ABCDEF"[n % 16], 1);
		size++;
		n /= 16;
	}
	return (size);
}
