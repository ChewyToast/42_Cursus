/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 11:24:56 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/05/27 11:26:00 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

int	ft_printf(const char *str, ...)
{
    va_list args;
    
    va_start(args, str);
    read_input(str, args);
    va_end(args);
}

int main(void)
{
    ft_printf("Caracter c: %c, string HW: %s\n", 'c', "Hello World");
    ft_printf("Esto es el numero 456: %d, y esto tambien: %i\n", 456, 456);
    return 0;
}