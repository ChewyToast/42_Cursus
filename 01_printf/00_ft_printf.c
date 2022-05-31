/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_ft_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:24:56 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/05/30 02:46:54 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	size_t	print_length;
	int		result;
	va_list	args;

	print_length = 0;
	va_start(args, str);
	result = read_input(str, args, &print_length);
	va_end(args);
	if (result == -1)
		return (-1);
	return (print_length);
}

int	main(void)
{
	int	rslt;

	rslt = ft_printf("%s\n%d\n%i\n%u\n%%\n", "123456789", 123456789, 123456789, 123456789);
	ft_printf("NUMBER OF CHARS: %d\n", rslt);
	printf("ORIGINAL RESULT: %p\n", "HELLO");
	ft_printf("MY OWN RESULT: %p\n", "HELLO");
	return 0;
}
