#include "get_next_line.h"

char	*ft_strjoin(char *read_buff, char *tmp)
{
	char	*str;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(read_buff) + ft_strlen(tmp);
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (0);
	while (size && read_buff[i])
	{
		str[i] = read_buff[i];
		i++;
		size--;
	}
	str[i] = '\0';
	free(read_buff);
	ft_strlcat(str, tmp, 0xffffffff);
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

char	*ft_substr(char *read_buff, size_t start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	len = ft_strlen(read_buff) - check_nl(read_buff);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	len++;
	while (len && read_buff[i + start])
	{
		str[i] = read_buff[i + start];
		i++;
		len--;
	}
	free(read_buff);
	return (str);
}

size_t	check_nl(const char *str)
{
	size_t	size;

	size = 0;
	if (!str)
		return (0);
	while (str[size] && str[size] != '\n')
		size++;
	if (!str[size])
		return (0);
	return (size);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
