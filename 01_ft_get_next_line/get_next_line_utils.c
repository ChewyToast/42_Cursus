#include "get_next_line.h"

char	*ft_strjoin(char *read_buff, char *tmp)
{
	char	*str;
	size_t	size;

	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
	size = ft_strlen(s1);
	while (size && read_buff[i])
	{
		str[i] = read_buff[i];
		i++;
		size--;
	}
	str[i] = '\0';
	free(read_buff);
	ft_strlcat(str, tmp, size + 1);
	free(tmp);
	return (str);
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

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
