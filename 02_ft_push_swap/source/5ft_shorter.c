/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5ft_shorter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:19:28 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/06/29 21:59:34 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// MAIN FUNCTION OF SHORTING, THERE WE CALL ALL THE SHORTER FUNCTIONS
int	shorter(t_stack **stack_a, t_stack **stack_b)
{
	while ((!is_shorted(stack_a) || (*stack_b)))
	{
		if ((*stack_a)->next)
			filling_stack_b(stack_a, stack_b);
		else
			refill_a(stack_a, stack_b);
	}
	return (1);
}

// FUNCTION TO CHECK IF THE STACK IS ALREADY SHORTED
int	is_shorted(t_stack **stack)
{
	int indx;
	t_stack	*tmp;

	tmp = *stack;
	indx = -2147483648;
	while (tmp)
	{
		if (tmp->num >= indx)
		{
			indx = tmp->num;
			tmp = tmp->next;
		}
		else
			return (0);
	}
	return (1);
}
