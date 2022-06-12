#include "get_next_line.h"

char	*get_next_line(const int fd)
{
	char		*read_buff;
	char		*rtrn_buff;
	static char	*saved_buff;

	if (BUFFER_SIZE <= 0 || !fd)
		return (NULL);
	if (!*saved_buff || !saved_buff || !check_nl(saved_buff))
	{
		read_buff = ft_read();
	}
}

ssize_t	check_nl(const char *str)
{
	while (*str && *str != '\n')
		str++;
	if (!*str)
		return (NULL);
	return (1);
}

char	*ft_read(const int fd)
{
	char	*read_buff;
	char	*tmp;
	ssize_t	checker;

	read_buff = malloc(sizeof(char) * 1);
	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (0);
	tmp[BUFFER_SIZE] = '\0';
	while ()
	{
		checker = read(fd, tmp, BUFFER_SIZE);
		if (checker == -1)
			return (0);
		else if (checker == 0)
			break ;
		read_buff = ft_strjoin(read_buff, tmp);
		if (!read_buff)
			return (0);
	}
}
