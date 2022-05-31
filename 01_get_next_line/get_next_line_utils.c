/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 10:02:56 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/05/31 23:28:28 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_counter;
	size_t	dst_counter;
	size_t	return_value;

	src_counter = 0;
	dst_counter = ft_strlen(dst);
	return_value = ft_strlen(src);
	if (size == 0)
		return (return_value);
	else if (size < ft_strlen(dst))
		return_value += size;
	else
	{
		return_value += ft_strlen(dst);
		size -= dst_counter;
		while (size > 1 && src[src_counter] != '\0')
		{
			dst[dst_counter] = src[src_counter];
			src_counter++;
			dst_counter++;
			size--;
		}
	dst[dst_counter] = '\0';
	}
	return (return_value);
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

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*f_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(sizeof(char) * size);
	if (str == NULL)
		return (0);
	str[size] = '\0';
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcat(str, s2, size);
	free(s2);
	return (str);
}

char	*get_line(char *line, char *str)
{
	size_t	size;
	size_t	i;

	size = 0;
	i = 0;
	line = NULL;
	while (str[size] != '\n' && str[size])
		size++;
	printf("\nSIZE: %ld\n", size);
	line = malloc(sizeof(char) * (size + 1));
	if (!line)
		return (0);
	line[size + 1] = '\0';
	while (line[i])
	{
		line[i] = str[i];
		i++;
	}
	printf("\n*****\n");
	printf("LINE DE GET LINE: %s", line);
	printf("\n*****\n");
	return (line);
}
