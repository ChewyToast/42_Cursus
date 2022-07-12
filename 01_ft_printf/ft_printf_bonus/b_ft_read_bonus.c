/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ft_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 11:47:47 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/06/12 11:47:56 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf_bonus.h"

static ssize_t	check_conversion(va_list args, const char *str);
static ssize_t	check_bonus(va_list args, const char *str);

ssize_t	ft_read(const char *str, va_list args)
{
	ssize_t	rslt;
	ssize_t	tmp;

	rslt = 0;
	while (*str)
	{
		tmp = 0;
		if (*str == '%')
		{
			tmp = check_conversion(args, (++str));
			if ((*str == ' ' && str[1] == '+')
				|| (*str == '+' && str[1] == ' '))
				str += 2;
			else if (*str == '#' || *str == ' ' || *str == '+')
				str++;
		}
		else
			tmp = ft_putchar(*str);
		if (tmp < 0)
			return (-1);
		str++;
		rslt += tmp;
	}
	return (rslt);
}

static ssize_t	check_conversion(va_list args, const char *str)
{
	ssize_t	rslt;

	rslt = 0;
	if (*str == 'c')
		rslt = ft_putchar(va_arg(args, int));
	else if (*str == 's')
		rslt = ft_putstr(va_arg(args, char *));
	else if (*str == 'p')
		rslt = ft_ptoa(va_arg(args, unsigned long long int));
	else if (*str == 'd' || *str == 'i')
		rslt = ft_itoa(va_arg(args, int), 0, 0);
	else if (*str == 'u')
		rslt = ft_uitoa(va_arg(args, unsigned int));
	else if (*str == 'x')
		rslt = ft_10to16(va_arg(args, unsigned int), 0, 0);
	else if (*str == 'X')
		rslt = ft_10to16(va_arg(args, unsigned int), 1, 0);
	else if (*str == '%')
		rslt = ft_putchar('%');
	else if (*str == '#' || *str == ' ' || *str == '+')
		rslt = check_bonus(args, str);
	return (rslt);
}

static ssize_t	check_bonus(va_list args, const char *str)
{
	ssize_t	rslt;

	rslt = 0;
	if (*str == '#')
	{
		str++;
		if (*str == 'x')
			rslt = ft_10to16(va_arg(args, unsigned int), 0, 1);
		else if (*str == 'X')
			rslt = ft_10to16(va_arg(args, unsigned int), 1, 1);
	}
	else if (*str == ' ' && str[1] != '+' && (str[1] == 'd' || str[1] == 'i'))
		rslt = ft_itoa(va_arg(args, int), 1, 0);
	else if (*str == ' ' && str[1] != '+' && str[1] == 's')
		rslt = ft_putstr(va_arg(args, char *));
	else if (*str == ' ' && str[1] == '+')
		rslt = ft_itoa(va_arg(args, int), 1, 1);
	else if (*str == '+')
		rslt = ft_itoa(va_arg(args, int), 0, 1);
	return (rslt);
}
