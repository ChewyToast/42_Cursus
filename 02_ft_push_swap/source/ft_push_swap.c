/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:19:28 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/06/21 11:20:13 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	fd_a;
	int	fd_b;

	fd_a = open("../files/a.txt", O_RDWR);
	fd_b = open("../files/b.txt", O_RDWR);
	if (fd_a < 1)
		return (ft_error());
	if (argc > 1)
		reader(fd_a, fd_b, argv);
}

ssize_t	reader(int fd_a, int fd_b, char **input)
{}

ssize_t	ft_error(void)
	return (ft_putstr_fd("Error\n", -2));