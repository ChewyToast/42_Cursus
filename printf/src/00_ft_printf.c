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
    size_t  print_length;
    va_list args;

    va_start(args, str);
    print_length = read_input(str, args, 0);
    va_end(args);
    return (print_length);
}

int main(void)
{
    int rslt;

    rslt = ft_printf("%s\n%d\n%i\n%u\n%%\n", "123456789", 123456789, 123456789, 123456789);
    ft_printf("NUMBER OF CHARS: %d\n", rslt);
    return 0;
}