/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 00:24:43 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/06/08 00:28:00 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

ssize_t	ft_putstr(const char *str, size_t *ln)
{
	size_t	size;

	while (str && *str)
	{
		if (ft_putchar(*str, ln) < 0)
			return (-1);
		str++;
	}
	return (0);
}
