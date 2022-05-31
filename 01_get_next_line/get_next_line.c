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

char	*get_next_line(const int fd)
{
	static char	*str;
	char		*rdstr;
	char		*rtstr;
	int			mode;
	size_t		*size;

	*size = 0;
	mode = ft_check_str(str, *size); //Vemos que tenemos en str, y si tenemos string con \n devolvemos con el pointer
	if (mode < 1)
	{
		if (mode == -1)
			str = "";
		rdstr = ft_read("", fd, size); //Iteramos el read creando y destruyendo mallocs hasta encontrar el \n o el EOF
		if (!rdstr)
			return (0);
	}
	if (mode == -1) //No hay string, por lo que hacemos sub del read
		rtstr = ft_substr(rdstr, 0, *size);
	else if (mode == 0) //Hay string pero no hasta \n
		rtstr = ft_strjoin(rdstr, ft_substr(rdstr, 0, *size), 1);
	else if (mode = 1) //Hay string y hay \n
		rtstr = ft_substr(str, 0, *size);
	// FALTA PONER EN CADA CASO EL STR, GUARDAR O BIEN EL READ - EL RTSTR, O BIEN STR - RTSTR
}

int	ft_check_str(char *str, size_t *size) //Vemos que tenemos en str, y si tenemos string con \n devolvemos con el pointer
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		*size = i;
		return (1);
	}
	return (0);
}

char	*ft_read(char *rdstr, int fd, size_t *size) //Iteramos el read creando y destruyendo mallocs hasta encontrar el \n o el EOF
{
	size_t		i;
	int			check;
	char		*tmp;

	check = 0;
	while (check == 0)
	{
		i = 0;
		tmp = malloc(sizeof(char) * BUFFER_SIZE);
		if (!tmp)
		{
			free(rdstr);
			return (0);
		}
		i = read(fd, tmp, BUFFER_SIZE);
		if (i == -1)
		{
			free(rdstr);
			free(tmp);
			return (0);
		}
		else if (i == 0)
			break ;
		i = 0;
		while (rdstr[i] != '\n' && rdstr[i])
			i++;
		if (rdstr[i] != '\n')
			check = 1;
		else
			rdstr = ft_strjoin(rdstr, tmp, 0);
	}
	*size = i;
	return (rdstr);
}
