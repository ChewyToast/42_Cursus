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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = ft_strlen(s);
	if (i > len)
		i = len;
	str = (char *)ft_calloc(sizeof(char *), i + 1);
	i = ft_strlen(s);
	if ((i < start && start > 1) || (len == 0 && i != 0))
		return (str);
	if (i > len)
		i = len;
	ft_memcpy(str, s + start, i);
	return (str);
}
