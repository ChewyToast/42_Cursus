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
#include <stdio.h>

static size_t	words_counter(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		if (*s != c && *s)
		{
			while (*s != c && *s)
				s++;
			words++;
		}
		while (*s == c && *s)
			s++;
	}
	return (words);
}

static size_t	chars_counter(char const *s, char c, size_t *indx)
{
	size_t	letras;

	letras = 0;
	while (s[*indx] == c && s[*indx])
		*indx += 1;
	while (s[*indx] != c && s[*indx])
	{
		*indx += 1;
		letras++;
	}
	return (letras);
}

static void	fill(char **str, char const *s, char c)
{
	size_t	charss;
	size_t	wordss;

	charss = 0;
	wordss = 0;
	while (*s)
	{
		charss = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
			str[wordss][charss++] = *(s++);
		wordss++;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	size_t	*indx;
	size_t	i;
	size_t	long_indx;
	char	**str;

	i = 0;
	long_indx = 0;
	indx = &long_indx;
	words = words_counter(s, c);
	str = (char **)ft_calloc(sizeof(char *), words);
	if (str == NULL)
		return (0);
	while (i < words)
	{
		str[i] = (char *)ft_calloc(sizeof(char),
				(chars_counter(s, c, indx) + 1));
		if (str[i] == NULL)
			return (0);
		i++;
	}
	fill(str, s, c);
	return (str);
}
