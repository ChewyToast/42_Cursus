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

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	size;
	size_t	tmp;

	size = 0;
	tmp = 0;
	while (s[size])
	{
		tmp = 0;
		while (s[size] != accept[tmp] && accept[tmp])
			tmp++;
		if (s[size] == accept[tmp])
			size++;
		else
			break ;
	}
	return (size);
}
