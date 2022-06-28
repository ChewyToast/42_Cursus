/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:19:28 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/06/24 12:30:40 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

// FUNCTION ADDS AT THE TOP OF THE STACK_DEST THE FIRST ITEM OF STACK_ORIGIN
void	ft_pab(t_stack **stack_dest, t_stack **stack_origin)
{
	t_stack	*tmp;

	tmp = *stack_origin;
	(*stack_origin) = tmp->next;
	tmp->next = *stack_dest;
	*stack_dest = tmp;
}

// FUNCTION SWAPS THE TWO FIRST ELEMENTS OF THE STACK
void	ft_sab(t_stack **stack)
{
	t_stack	*tmp;

	if ((*stack)->next)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = (*stack)->next;
		(*stack)->next = tmp;
	}
}