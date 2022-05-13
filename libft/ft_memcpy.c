/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:59:50 by marvin            #+#    #+#             */
/*   Updated: 2022/05/12 00:46:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	unsigned char		*str_dest;
	const unsigned char	*str_ori;

	str_dest = dest;
	str_ori = src;
	while (n > 0)
	{
		*str_dest = *str_ori;
		str_dest++;
		str_ori--;
		n--;
	}
	return (dest);
}
