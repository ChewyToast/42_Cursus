/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:19:28 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/06/24 12:30:31 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}	t_stack;

/*FT_CHECK_INPUT*/
// function chain to check the input
size_t	check_input(char **input);
// function to show the error msg and return 0
size_t	ft_error(void);

/*STACK_FUNCTIONS*/
// function fills the stack_a with the input
size_t	fill_stack(char **input, t_stack **stack_a);
// function creates a new stack item with the num of the parametrer
t_stack	*create_cont(int num);
// function adds at the end of the stack a new item
size_t	add_at_end(t_stack **stack, t_stack *new_item);
// function to free all the stack
void	ft_free(t_stack **stack);
// function to see the stack, just a checker for the programer
void	show_stack(t_stack **stack);

/*STACK_OPERATIONS*/
// FUNCTION ADDS AT THE TOP OF THE STACK_DEST THE FIRST ITEM OF STACK_ORIGIN
void	ft_pab(t_stack **stack_dest, t_stack **stack_origin);
// function swaps the two first elements of the stack
void	ft_sab(t_stack **stack);

#endif
