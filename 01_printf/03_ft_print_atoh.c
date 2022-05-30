/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_ft_print_atoh.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:58:04 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/05/30 11:06:02 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t	ft_print_atoh(char *str)
{
	size_t	size;

	while (!(*str))
	{
		ft_putchar_fd("0123456789abcdef"[*str++ % 16], 1);
		ft_putchar_fd("0123456789abcdef"[*str++ / 16], 1);
	}
	return (0);
}
