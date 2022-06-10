/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 02:55:37 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/06/08 00:13:25 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	read_input(const char *str, va_list args, size_t *print_length)
{
	int	rslt;

	rslt = 0;
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
				rslt = ft_ptoa(va_arg(args, unsigned long long int),
						(print_length));
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
	if (*str == 'd' || *str == 'i')
		rslt = ft_int(va_arg(args, int), 0, 1, print_length);
	else if (*str == 'u')
		rslt = ft_int(0, va_arg(args, unsigned int), 2, print_length);
	else if (*str == 'x')
		rslt = ft_16to10(va_arg(args, unsigned int), 0, print_length);
	else if (*str == 'X')
		rslt = ft_16to10(va_arg(args, unsigned int), 1, print_length);
	else if (*str == '%')
		*print_length += ft_putchar_fd(*str, 1);
	return (rslt);
}