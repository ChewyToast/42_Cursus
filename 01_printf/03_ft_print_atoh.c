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
	int	chr;

	while (*str)
	{
		chr = 0;
		ft_putchar_fd('\\', 1);
		chr += 10 *("0123456789abcdef"[*str / 16], 1);
		chr += ("0123456789abcdef"[*str % 16], 1);
		ft_putchar_fd(chr, 1);
		str++;
	}
	return (0);
}
