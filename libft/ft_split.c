/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:25:32 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/05/24 01:24:45 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	words_counter(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			words++;
		s++;
	}
	return (words);
}

char	**ft_freedom(char **str, size_t indx)
{
	while (indx-- > 0)
		free(str[indx]);
	free(str);
	return (0);
}

char	**fill(char **str, char const *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	indx;

	i = 0;
	start = 0;
	indx = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			start = i + 1;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			str[indx] = ft_substr(s, start, i - start + 1);
			if (!str[indx])
			{
				return (ft_freedom(str, indx));
			}
			indx++;
		}
		i++;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	str = ft_calloc(sizeof(char *), (words_counter(s, c) + 1));
	if (!str)
		return (0);
	str = fill(str, s, c);
	return (str);
}
