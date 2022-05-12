/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:44:48 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/05/11 12:00:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (('a' <= str[i]) && (str[i] <= 'z'))
			j++;
		if (('A' <= str[i]) && (str[i] <= 'Z'))
			j++;
		i++;
	}
	if (i < 1 || i == j)
		return (1);
	else
		return (0);
}
