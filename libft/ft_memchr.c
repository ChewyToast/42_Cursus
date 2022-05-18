/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:00:09 by marvin            #+#    #+#             */
/*   Updated: 2022/05/12 00:16:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (!n)
		return (0);
	while ((--n > 0) && *(unsigned char *)s != (unsigned char)c)
		s++;
	if (*(unsigned char *)s == (unsigned char)c)
		return ((unsigned char *)s);
	return (0);
}
