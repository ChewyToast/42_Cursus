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
	char	*str;
	size_t	size;

	size = ft_strlen(s);
	if (!(start + len <= size) && size > 0)
		len = size;
	else
		len++;
	str = malloc(sizeof(char) * len);
	if ((!str) || (!s && len))
		return (0);
	if (!*s)
		return ("");
	ft_strlcpy(str, s + start, len);
	return (str);
}