/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 00:20:18 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/05/23 00:21:48 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

ssize_t	ft_putchar(char c, size_t *ln)
{
	ssize_t	rslt;

	rslt = write(1, &c, 1);
	if (!rslt)
		return (-1);
	*ln += 1;
	return (0);
}
