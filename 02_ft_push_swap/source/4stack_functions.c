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

// FUNCTION CREATES A T_STACK WITH THE VALUE OF THE PARAMETER
t_stack	*create_cont(int num)
{
	t_stack	*str;

	str = malloc(sizeof(t_stack) * 1);
	if (!str)
		return (0);
	str->content = num;
	str->next = NULL;
	return (str);
}

// FUNCTION ADDS AT THE END OF THE STACK, A NEW NUMBER
void	add_num(t_stack **lst, t_stack *nlst)
{
	if (!(*lst))
		(*lst) = nlst;
	else
	{
		while ((*lst)->next)
			(*lst) = (*lst)->next;
		(*lst)->next = nlst;
	}
}
