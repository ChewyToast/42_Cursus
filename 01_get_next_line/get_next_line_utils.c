/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:02:56 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/05/27 12:11:04 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	i;

	i = 0;
	if (!size)
		return (ft_strlen(src));
	while ((size - 1) > 0 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
		size--;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size;

	size = ft_strlen(s);
	if (!*s || size < start)
		return (ft_calloc(sizeof(char), 1));
	if ((len + start) > size)
		len = size - start;
	str = malloc(sizeof(char) * (len + 1));
	if ((!str) || (!s && len))
		return (0);
	ft_strlcpy(str, s + start, (len + 1));
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)ft_calloc(sizeof(char), size);
	if (str == NULL)
		return (0);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, size);
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*mall;

	if ((nmemb * size) > 0xffffffff)
		return (NULL);
	mall = malloc (size * nmemb);
	if (mall == NULL)
		return (NULL);
	size *= nmemb;
	while (size--)
		mall[size] = 0;
	return (mall);
}
