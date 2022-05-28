/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 00:24:43 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/05/23 10:36:43 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

size_t	ft_putstr_fd(const char *str, int fd)
{
	size_t	size;

	size = ft_strlen(str);
	write(fd, str, size);
	return (size);
}
