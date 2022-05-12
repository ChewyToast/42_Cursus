/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ctype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 12:01:13 by marvin            #+#    #+#             */
/*   Updated: 2022/05/12 01:28:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <unistd.h>

void	tester(void);

int	main(void)
{
	tester();
}

void	tester(void)
{
	int	i;
	int	j;

	printf("\n      --- FT_ISALPHA ---\n");
	j = 0;
	i = -131;
	while (i <= 321)
	{
		if ((isalpha(i)) && (ft_isalpha(i)))
			i++;
		else if ((!isalpha(i)) && (!ft_isalpha(i)))
			i++;
		else
		{
			printf("\n- Test with: %d\n", i);
			printf("ESTIMATED: %d\nRECIVED: %d\n", isdigit(i), ft_isdigit(i));
			i++;
			j++;
		}
	}
	if (j == 0)
		printf("\nMUY BIEN, TODOS LOS TESTS OK!!\n\n");
	else
		printf("\nUPS, HAY ALGO MAL, REVISA TU CODIGO\n\n");
	printf("\n      --- FT_ISDIGIT ---\n");
	j = 0;
	i = -131;
	while (i <= 321)
	{
		if ((isdigit(i)) && (ft_isdigit(i)))
			i++;
		else if ((!isdigit(i)) && (!ft_isdigit(i)))
			i++;
		else
		{
			printf("\n- Test with: %d\n", i);
			printf("ESTIMATED: %d\nRECIVED: %d\n", isdigit(i), ft_isdigit(i));
			i++;
			j++;
		}
	}
	if (j == 0)
		printf("\nMUY BIEN, TODOS LOS TESTS OK!!\n\n");
	else
		printf("\nUPS, HAY ALGO MAL, REVISA TU CODIGO\n\n");
	printf("\n      --- FT_ISALNUM ---\n");
	j = 0;
	i = -131;
	while (i <= 321)
	{
		if ((isalnum(i)) && (ft_isalnum(i)))
			i++;
		else if ((!isalnum(i)) && (!ft_isalnum(i)))
			i++;
		else
		{
			printf("\n- Test with: %d\n", i);
			printf("ESTIMATED: %d\nRECIVED: %d\n", isalnum(i), ft_isalnum(i));
			i++;
			j++;
		}
	}
	if (j == 0)
		printf("\nMUY BIEN, TODOS LOS TESTS OK!!\n\n");
	else
		printf("\nUPS, HAY ALGO MAL, REVISA TU CODIGO\n\n");
	printf("\n      --- FT_ISASCII ---\n");
	j = 0;
	i = -131;
	while (i <= 300)
	{
		if ((isascii(i)) && (ft_isascii(i)))
			i++;
		else if ((!isascii(i)) && (!ft_isascii(i)))
			i++;
		else
		{
			printf("\n- Test with: %d\n", i);
			printf("ESTIMATED: %d\nRECIVED: %d\n", isascii(i), ft_isascii(i));
			i++;
			j++;
		}
	}
	if (j == 0)
		printf("\nMUY BIEN, TODOS LOS TESTS OK!!\n\n");
	else
		printf("\nUPS, HAY ALGO MAL, REVISA TU CODIGO\n\n");
	printf("\n      --- FT_ISPRINT ---\n");
	j = 0;
	i = 0;
	while (i <= 127)
	{
		if ((isprint(i)) && (ft_isprint(i)))
			i++;
		else if ((!isprint(i)) && (!ft_isprint(i)))
			i++;
		else
		{
			printf("\n- Test with: %d\n", i);
			printf("ESTIMATED: %d\nRECIVED: %d\n", isprint(i), ft_isprint(i));
			i++;
			j++;
		}
	}
	if (j == 0)
		printf("\nMUY BIEN, TODOS LOS TESTS OK!!\n\n");
	else
		printf("\nUPS, HAY ALGO MAL, REVISA TU CODIGO\n\n");
}
