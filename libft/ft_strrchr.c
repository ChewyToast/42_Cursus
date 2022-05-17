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

char	*ft_strrchr(const char *s, int c)
{
	const void	*init;

	init = s;
	s += ft_strlen(s);
	while (s != init && *s != c)
		s--;
	if (*s == c)
		return ((char *)s);
	else
		return (0);
}
