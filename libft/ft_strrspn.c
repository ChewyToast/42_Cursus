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

size_t	ft_strrspn(const char *s, const char *accept)
{
	size_t	size;
	size_t	tmp;

	size = ft_strlen(s) - 1;
	tmp = 0;
	while (s[size] && size)
	{
		tmp = 0;
		while (s[size] != accept[tmp] && accept[tmp])
			tmp++;
		if (s[size] == accept[tmp])
			size--;
		else
			break ;
	}
	size++;
	return (size);
}
