/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 22:19:58 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/05/27 12:13:53 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(const int fd)
{
	char	*line;
	char	*tmp;
	char	buff[1];
	int		fr;

	tmp = "";
	fr = read(fd, buff, 1);
	while (fr > 0 && buff[0] != '\n')
	{
		line = ft_strjoin(tmp, buff);
		free(tmp);
		tmp = ft_substr(line, 0, 0xFFFFFFFF);
		free(line);
		fr = read(fd, buff, 1);
	}
	if (buff[0] == '\n')
	{
		line = ft_strjoin(tmp, buff);
		free(tmp);
	}
	if (fr < 0)
		return (0);
	return (line);
}

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
	else if (size < (size_t)ft_strlen(dst))
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
