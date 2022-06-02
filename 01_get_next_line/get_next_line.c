/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 22:19:58 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/06/02 23:07:28 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
/*
	printf("\n   MODE: %d", mode);
	printf("\n-1 Str: %s", str);
	printf("\n-1 RDstr: %s", rdstr);
	printf("\n-1 RTstr: %s", rtstr);
*/
int	main(void)
{
	int		fd;
	char	*st;
	int		cnt;

	cnt = 7;
	st = "";
	fd = open("prueba.txt", O_RDONLY);
	while (cnt >= 0)
	{
		st = get_next_line(fd);
		printf("\nRESULT\n");
		printf("%s", st);
		free(st);
		cnt--;
	}
	close(fd);
}

char	*get_next_line(const int fd)
{
	static char	*str;
	char		*rdstr;
	char		*rtstr;
	int			mode;
	size_t		size;

	size = 0;
	rtstr = "";
	rdstr = "";
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	mode = ft_check_str(str, &size);
	if (mode < 1)
	{
		if (mode == -1)
			str = "";
		rdstr = ft_read("", fd, &size);
		if (!rdstr)
			return (0);
	}
	if (mode == -1)
	{
		rtstr = ft_substr(rdstr, 0, size);
		str = ft_substr(rdstr, size, 0xffffffff);
		free_str(rdstr);
	}
	else if (mode == 0)
	{
		rtstr = ft_strjoin(str, ft_substr(rdstr, 0, size), 1);
		str = ft_substr(rdstr, size, 0xffffffff);
		free_str(rdstr);
	}
	else if (mode == 1)
	{
		rtstr = ft_substr(str, 0, size);
		str = ft_substr(str, size, 0xffffffff);
	}
	return (rtstr);
}

int	ft_check_str(char *str, size_t *size)
{
	size_t	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		*size = i + 1;
		return (1);
	}
	return (0);
}

char	*ft_read(char *rdstr, int fd, size_t *size)
{
	int			i;
	int			check;
	char		*tmp;

	check = 0;
	while (check == 0)
	{
		i = 0;
		tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		tmp[BUFFER_SIZE] = '\0';
		if (!tmp)
			return ((char *)free_str(rdstr));
		i = read(fd, tmp, BUFFER_SIZE);
		if (i == -1)
		{
			free_str(rdstr);
			return (free_str(tmp));
		}
		rdstr = ft_strjoin(rdstr, tmp, 0);
		if (!rdstr)
		{
			free_str(tmp);
			return (free_str(rdstr));
		}
		if (i == 0 || ft_strchrpos(rdstr, '\n'))
			break ;
	}
	free_str(tmp);
	*size = ft_strchrpos(rdstr, '\n') + 1;
	return (rdstr);
}

size_t	ft_strchrpos(const char *s, int c)
{
	size_t	size;

	size = 0;
	while (s[size] != (char)c && s[size] != '\0')
		size++;
	if (s[size] == (char)c || (s[size] == '\0' && (char)c == '\0'))
		return (size);
	else
		return (0);
}

char	*free_str(char *str)
{
	if (!str || !*str)
		return (0);
	free(str);
	return (0);
}
