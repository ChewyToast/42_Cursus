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
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		if (check_input(argv))
		{
			printf("Correct input");
			if (!fill_stack(argv, &stack_a))
				return (0);
			show_stack(&stack_a);
			ft_free(&stack_a);
			ft_free(&stack_b);
		}
		else
			printf("Wrong input\n");
	}
	else
		printf("Invalid input\n");
	return (0);
}

// FUNTION TO SHOW THE ERROR MSG AND RETURN 0
size_t	ft_error(void)
{
	printf("Error\n");
	return (0);
}
