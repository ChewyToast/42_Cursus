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
#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s != c && *s != '\0')
		s++;
	if (*s == c || (*s == '\0' && c == '\0'))
		return ((char *)s);
	else
		return (0);
}
/*
int	main(int av, char **argv)
{
	printf("EXPECTED: %s\n", strchr(argv[1], argv[2][0]));
	printf("My: %s\n", ft_strchr(argv[1], argv[2][0]));
	printf("EXPECTED: %s\n", strchr("0x55adad865020: \"teste\"", '\0'));
        printf("My: %s\n", ft_strchr("0x55adad865020: \"teste\"", '\0'));
}*/
