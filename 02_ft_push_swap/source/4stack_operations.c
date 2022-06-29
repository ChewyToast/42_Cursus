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

// FUNCTION SWAPS THE TWO FIRST ELEMENTS OF THE STACK
void	ft_sab(t_stack **stack)
{
	printf("\n\nsab");
	t_stack	*tmp;

	if ((*stack) && ((*stack)->next))
	{
		tmp = (*stack)->next;
		(*stack)->next = tmp->next;
		tmp->next = *(stack);
		*stack = tmp;
	}
}

// FUNCTION ADDS AT THE TOP OF THE STACK_DEST THE FIRST ITEM OF STACK_ORIGIN
void	ft_pab(t_stack **stack_dest, t_stack **stack_origin)
{
	printf("\n\npab");
	t_stack	*tmp;

	if (*stack_origin && *stack_dest)
	{
		tmp = *stack_origin;
		(*stack_origin) = (*stack_origin)->next;
		tmp->next = *stack_dest;
		*stack_dest = tmp;
	}
	else if (*stack_origin && !(*stack_dest))
	{
		*stack_dest = *stack_origin;
		*stack_origin = (*stack_origin)->next;
		(*stack_dest)->next = NULL;
	}
}

// FUNCTION TO SHIFT UP ALL THE ELEMENTS OF THE STACK
void	ft_rab(t_stack **stack)
{
	printf("\n\nrab");
	t_stack	*tmp;

	if (*stack && ((*stack)->next))
	{
		tmp = *stack;
		*stack = (*stack)->next;
		add_at_end(stack, tmp);
		tmp->next = NULL;
	}
}

// FUNCTION TO SHIFT DOWN ALL THE ELEMENTS OF THE STACK
void	ft_rrab(t_stack **stack)
{
	printf("\n\nrrab");
	t_stack	*tmp;
	t_stack	*tmp2;

	if (*stack && ((*stack)->next))
	{
		tmp = *stack;
		tmp2 = tmp->next;
		while (tmp2->next)
		{
			tmp = tmp->next;
			tmp2 = tmp->next;
		}
		tmp->next = NULL;
		tmp2->next = *stack;
		*stack = tmp2;
	}
}
