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

int	main()
{
	int	fd;
	char	*st;
	
	fd = open("prueba.txt", O_RDONLY);
	while (st)
	{
		st = get_next_line(fd);
		printf("\n%s", st);
	}
	close(fd);
}

char	*get_next_line(const int fd)
{
	static char	*str;
	char		*rdstr;
	char		*rtstr;
	int			mode;

	mode = ft_check_str(str);
	if (mode < 1)
	{
		if (mode == -1)
			str = "";
		rdstr = malloc(sizeof(char) * (BUFFER_SIZE + 1)); // Create a read string
		if (!rdstr || !read(fd, rdstr, BUFFER_SIZE)) // Read into read string
			return ((char *)ft_clean(rdstr));
		rdstr[BUFFER_SIZE] = '\0';
		str = f_strjoin(str, rdstr); // Create a total str and free rdstr
	}
	rtstr = str;
	mode =get_line(rtstr, str); // Take only the line to return string
	if (!mode)
		return ((char *)ft_clean(rtstr));
	if (!trim_str(str))
		return(0);
	return (rtstr);
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

int	trim_str(char *str)
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
		return (ft_clean(tmp));
	ft_strlcpy(str, tmp, 0xffffffff);
	free(tmp);
	return (1);
}