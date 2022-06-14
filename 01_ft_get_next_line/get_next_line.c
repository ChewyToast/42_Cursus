#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*st;
	char	forst;
	int		cnt;

	cnt = 1;
	forst = '1';
	st = &forst;
	fd = open("prueba.txt", O_RDONLY);
	write(1, "\nHI\n", 4);
	while (cnt)
	{
		st = get_next_line(fd);
		if (st == NULL)
			break ;
		printf("\nRESULT\n");
		printf("%s", st);
		free(st);
	}
	close(fd);
}

char	*get_next_line(const int fd)
{
	char		*total_buff;
	char		*rtrn_buff;
	static char	*saved_buff;

	write(1, "\nHI\n", 4);
	if (BUFFER_SIZE < 1 || !fd)
		return (NULL);
	if (!saved_buff || !check_nl(saved_buff))
	{
		total_buff = ft_read(fd, saved_buff);
		if (!total_buff)
			return (0);
		rtrn_buff = copy_line(total_buff);
		saved_buff = ft_substr(total_buff, check_nl(total_buff) + 1, (ft_strlen(total_buff) - check_nl(total_buff)));
	}
	else
	{
		rtrn_buff = copy_line(saved_buff);
		saved_buff = ft_substr(saved_buff, check_nl(saved_buff) + 1, (ft_strlen(saved_buff) - (check_nl(saved_buff) + 1)));
	}
	return (rtrn_buff);
}
char	*copy_line(char *buff)
{
	char	*rtrn_buff;
	size_t	size;

	size = 0;
	while (buff[size] && buff[size] != '\n')
		size++;
	rtrn_buff = malloc(sizeof(char) * size + 2);
	rtrn_buff[size + 1] = '\0';
	if (!rtrn_buff)
		return (0);
	size = 0;
	while (buff[size] && buff[size] != '\n')
	{
		rtrn_buff[size] = buff[size];
		size++;
	}
	rtrn_buff[size] = buff[size];
	return (rtrn_buff);
}

char	*ft_read(const int fd, char *saved_buff)
{
	char	*read_buff;
	char	*tmp;
	ssize_t	checker;

	checker = ft_strlen(saved_buff);
	read_buff = malloc(sizeof(char) * (checker + 1));
	if (!read_buff)
		return (0);
	checker = 0;
	if (saved_buff)
	{
		while (saved_buff[checker])
		{
			read_buff[checker] = saved_buff[checker];
			checker++;
		}
	}
	read_buff[checker] = 0;
	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
	{
		free(read_buff);
		return (0);
	}
	tmp[BUFFER_SIZE] = '\0';
	while (1)
	{
		checker = read(fd, tmp, BUFFER_SIZE);
		if (checker == -1)
		{
			free(read_buff);
			free(tmp);
			return (0);
		}
		else if (checker)
		{
			read_buff = ft_strjoin(read_buff, tmp);
			if (!read_buff)
				return (0);
		}
		if (check_nl(read_buff) || !checker)
			break;
	}
	free(tmp);
	if (saved_buff)
		free(saved_buff);
	return (read_buff);
}
