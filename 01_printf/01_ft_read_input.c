/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_ft_read_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 02:55:37 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/05/30 10:56:01 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	read_input(const char *str, va_list args, size_t *print_length)
{
	int	rslt;

	slt = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c')
				*print_length += ft_putchar_fd(va_arg(args, int), 1);
			else if (*str == 's')
				*print_length += ft_putstr_fd(va_arg(args, char *), 1);
			else if (*str == 'p')
				*print_length += ft_print_atoh(va_arg(args, char *));
			else if (*str == 'd' || *str == 'i')
				rslt = ft_int(va_arg(args, int), 0, 1, print_length);
			else
				rslt = extra_read_input(str, args, print_length);
		}
		else
			*print_length += ft_putchar_fd(*str, 1);
		str++;
		if (rslt == -1)
			return (-1);
	}
	return (rslt);
}

int	extra_read_input(const char *str, va_list args, size_t *print_length)
{
	int	rslt;

	rslt = 0;
	if (*str == 'u')
		rslt = ft_int(0, va_arg(args, long int), 2, print_length);
//    else if (*str == 'x')
//    else if (*str == 'X')
	else if (*str == '%')
		*print_length += ft_putchar_fd(*str, 1);
	return (rslt);
}
