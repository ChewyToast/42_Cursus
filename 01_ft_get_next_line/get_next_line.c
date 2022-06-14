#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*st;
	int		cnt;

	cnt = 5;
	fd = open("prueba.txt", O_RDONLY);
	while (cnt > 1)
	{
		st = get_next_line(fd);
		printf("%s", st);
		free(st);
		cnt--;
	}
	close(fd);
}

char	*get_next_line(const int fd)
{
	char		*rtrn_buff;
	static char	*total_buff;

	if (BUFFER_SIZE < 1 || fd <= 0)
		return (NULL);
	if (!total_buff || !check_nl(total_buff))
	{
		total_buff = ft_read(fd, total_buff);
		if (!total_buff)
			return (NULL);
	}
	printf("\nstr: %s\n", total_buff);
	rtrn_buff = copy_line(total_buff);
	if (rtrn_buff)
		return (NULL);
	total_buff = ft_substr(total_buff, ft_strlen(rtrn_buff), (ft_strlen(total_buff) - ft_strlen(rtrn_buff)));
	if (!total_buff)
		return (NULL);
	return (rtrn_buff);
}
char	*copy_line(char *total_buff)
{
	char	*rtrn_buff;
	size_t	size;

	size = 0;
	while (total_buff[size] && total_buff[size] != '\n')
		size++;
	rtrn_buff = malloc(sizeof(char) * (size + 2));
	if (!rtrn_buff)
		return (NULL);
	rtrn_buff[size + 1] = '\0';
	size = 0;
	while (total_buff[size] && total_buff[size] != '\n')
	{
		rtrn_buff[size] = total_buff[size];
		size++;
	}
	rtrn_buff[size] = total_buff[size];
	return (rtrn_buff);
}

char	*ft_read(const int fd, char *total_buff)
{
	char	*tmp;
	ssize_t	chk;

	chk = 1;
	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	while (chk < 1 && !check_nl(total_buff))
	{
		chk = read(fd, tmp, BUFFER_SIZE);
		if (chk > 0)
		{
			printf("\nhi\n");
			tmp[chk] = '\0';
			total_buff = ft_strjoin(total_buff, tmp);
			printf("\nstr: %s\n", total_buff);
		}
	}
	free(tmp);
	if (chk == -1)
		return (NULL);
	return (total_buff);
}
