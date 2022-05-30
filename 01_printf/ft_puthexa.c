/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:09:48 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/05/30 11:10:52 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_puthexa(char *str)
{
	size_t	size;

	size = ft_strlen(str);
	while (!(*str))
		ft_putchar_fd(("0123456789abcdef"[*str++ / 16]), 1);
	return (size);
}
