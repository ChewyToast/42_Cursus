/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:19:28 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/06/24 12:30:21 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// MAIN FUNCTION, THERE WE SEE THE NUM OF ARGS AND START THE PROGRAM
int	main(int argc, char **argv)
{
//	t_stack	stack_a;
//	t_stack	stack_b;

	if (argc > 1)
	{
		if (check_input(argv))
		{
			printf("Correct input\n");
		}
		else
			printf("Wrong input\n");
	}
	else
		printf("Invalid input\n");
	return (0);
}
