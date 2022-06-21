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

int	ft_atoi(const char *nptr)
{
	int	num;
	int	symb;

	num = 0;
	symb = 1;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-')
	{
		symb = -1;
		nptr++;
	}
	else if (*nptr == '+')
		nptr++;
	while (*nptr >= 48 && *nptr <= 57)
	{
		num *= 10;
		num = num + (*nptr - 48);
		nptr++;
	}
	return (num * symb);
}
