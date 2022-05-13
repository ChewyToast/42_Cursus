/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 11:59:35 by marvin            #+#    #+#             */
/*   Updated: 2022/05/12 00:16:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int	i;

	i = 0;
	while (size > 0 || *src == '\0')
	{
		if (dst[i] != '\0')
			size--;
		else
		{
			dst[i] = *src;
			size--;
			src++;
		}
		i++;
	}
	dst[i] = '\0';
	return (i);
}
