/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_16to10.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 22:36:42 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/06/08 00:21:11 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	print_rslt(char *num, int size)
{
	size--;
	while (num[size])
	{
		ft_putchar_fd(num[size], 1);
		size--;
	}
}

int	ft_16to10(unsigned int n, int mode, size_t *print_length)
{
	size_t	size;
	char	*num;

	num = malloc(sizeof(char) * 11);
	if (num == NULL)
		return (-1);
	size = 0;
	while (n)
	{
		if (!mode)
			num[size] = ("0123456789abcdef"[n % 16]);
		else
			num[size] = ("0123456789ABCDEF"[n % 16]);
		size++;
		n /= 16;
	}
	num[size] = '\0';
	print_rslt(num, (int)size);
	*print_length += size;
	free(num);
	return (0);
}
