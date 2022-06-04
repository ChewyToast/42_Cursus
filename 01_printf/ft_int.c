/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_ft_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:57:26 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/05/30 10:57:38 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t	ft_int(int n, unsigned int n2, int method, size_t *print_length)
{
	char	*num;
	size_t	size;

	if (method == 1)
		num = ft_itoa(n);
	else if (method == 2)
		num = ft_itoa_unsigned(n2);
	if (!num)
		return (-1);
	size = ft_strlen(num);
	write(1, num, size);
	*print_length += size;
	free(num);
	return (1);
}
