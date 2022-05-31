/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 22:19:58 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/05/31 23:27:32 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*st;
	int		cnt;

	cnt = 2;
	st = "";
	fd = open("prueba.txt", O_RDONLY);
	while (cnt >= 0)
	{
		st = get_next_line(fd);
		printf("\n%s\n", st);
		cnt--;
	}
	close(fd);
}

int	ft_clean(char *str)
{
	free(str);
	return (0);
}

char	ft_check_str(char *str)
{
	if (!str)
		return (-1);
	while (*str && *str != '\n')
		str++;
	if (*str == '\n')
		return (1);
	return (0);
}

char	*trim_str(char *str)
{
	char		*tmp;
	size_t		i;

	i = 0;
	tmp = malloc(sizeof(char) * ft_strlen(str));
	while (str[i - 1] != '\n' && str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	free(str);
	str = malloc(sizeof(char) * (ft_strlen(tmp) + 1));
	if (!str)
	{
		free(tmp);
		return (0);
	}
	ft_strlcpy(str, tmp, 0xffffffff);
	free(tmp);
	return (str);
}

char	*get_next_line(const int fd)
{
	static char	*str;
	char		*rdstr;
	char		*rtstr;
	int			mode;

	mode = ft_check_str(str);
	rtstr = "";
	if (mode < 1)
	{
		if (mode == -1)
			str = "";
		rdstr = malloc(sizeof(char)
				* (BUFFER_SIZE + 1));
		if (!rdstr || !read(fd, rdstr, BUFFER_SIZE))
		{
			ft_clean(rdstr);
			return (0);
		}
		rdstr[BUFFER_SIZE] = '\0';
		printf("\n-----------------");
		printf("\n0Str: %s\n", str);
		printf("0RdStr: %s\n", rdstr);
		printf("0RtStr: %s\n", rtstr);
		str = f_strjoin(str, rdstr);
	}
	rtstr = get_line(rtstr, str);
	printf("\n1Str: %s\n", str);
	printf("1RdStr: %s\n", rdstr);
	printf("1RtStr: %s\n", rtstr);
	if (!rtstr)
	{
		free(rtstr);
		return (0);
	}
	str = trim_str(str);
	if (!str)
		return (0);
	printf("\n2Str: %s\n", str);
	printf("2RdStr: %s\n", rdstr);
	printf("2RtStr: %s\n", rtstr);
	printf("\n-----------------");
	return (rtstr);
}
