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

static size_t	chars_counter(char const *s, char c)
{
	size_t	letras;
	while (*(s++) == c && *s)
		;
	while (*s != c && *s != '\0')
	{
		s++;
		letras++;
	}
	printf("\nRETURN DE CHARS_COUNTER: %ld\n", letras);
	return (letras);
}

static void	fill(char **str, char const *s, char c)
{
	size_t	tmp;

	tmp = 0;
	while (*(s++))
	{
		while (*s == c)
			s++;
		while (*s != c)
			*str[tmp] = *s;
		tmp++;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	size_t	chars;
	size_t	indx;
	char	**str;

	words = words_counter(s, c);
	printf("\nNUMERO DE PALABRAS: %ld\n", words);
	str = (char **)ft_calloc(sizeof(char *), words);
	printf("\nMEMORIA PARA %ld PALABRAS\n", words);
	chars = 0;
	indx = 0;
	while (words--)
	{
		chars = chars_counter(s + indx, c);
		printf("\nVUELTA %ld: , numero de letras: %ld", words, chars);
		indx += chars;
		str[words] = (char *)ft_calloc(sizeof(char), chars);
	}
	fill(str, s, c);
	return (str);
}
