/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:24:56 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/06/09 23:04:11 by bmoll-pe         ###   ########.fr       */
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
/*
int	main(void)
{
	int		rslt;
	int		ori_rslt;
	char	*pst = "Que onda";

	printf("\n*MY FT_PRINTF*\n\n");
	rslt = ft_printf(("%s\n%d\n%i\n%u\n%%\n"), "",
			(123456789),
			(123456789),
			(123456789));
	rslt += ft_printf("MY OWN RESULT: %p\n", pst);
	rslt += ft_printf("This num in hexa (x): %x\n", 123123);
	rslt += ft_printf("This num in hexa (X): %X\n", 123123);
	ft_printf("NUMBER OF CHARS: %d\n", rslt);
	printf("\n-----------------\n");
	printf("\n*ORIGINAL PRINTF*\n\n");
	ori_rslt = printf(("%s\n%d\n%i\n%u\n%%\n"), "",
			(123456789),
			(123456789),
			(123456789));
	ori_rslt += printf("ORIGINAL RESULT: %p\n", pst);
	ori_rslt += printf("This num in hexa (x): %x\n", 123123);
	ori_rslt += printf("This num in hexa (X): %X\n", 123123);
	printf("NUMBER OF CHARS: %d\n", ori_rslt);
	return (0);
}*/
