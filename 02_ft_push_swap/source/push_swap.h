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
// function to organize program processes
ssize_t	startup(char **argv);
// function to show the error msg and return -1
size_t	ft_error(void);

/*STACK_FUNCTIONS*/
// function fills the stack_a with the input
size_t	fill_stack(char **input, t_stack **stack_a);
// function creates a new stack item with the num of the parametrer
t_stack	*create_cont(int num);
// function adds at the end of the stack a new item
size_t	add_at_end(t_stack **stack, t_stack *new_item);
// function to return the size of the stack
size_t	stack_len(t_stack **stack);
// function to free all the stack
void	ft_free(t_stack **stack);
// function to see the stack, just a checker for the programer
//void	show_stack(t_stack **stack_a, t_stack **stack_b);

/*STACK_OPERATIONS*/
// function swaps the two first elements of the stack
void	ft_sab(t_stack **stack);
// function adds at the top of the stack_dest the first item of stack_origin
void	ft_pab(t_stack **stack_dest, t_stack **stack_origin);
// function to shift up all the elements of the stack
void	ft_rab(t_stack **stack);
// function to shift down all the elements of the stack
void	ft_rrab(t_stack **stack);

/*FT_SHORTER*/
// main function of shorting, there we call all the shorter functions
int		shorter(t_stack **stack_a, t_stack **stack_b);
// function to check if the stack is already shorted
int		is_shorted(t_stack **stack);

/*SHORTER_FUNCTIONS*/
// function to find the smallest num of the stack
size_t	find_smallest(t_stack **stack);
// function pass the stack_a to stack_b in descending order
int		filling_stack_b(t_stack **stack_a, t_stack **stack_b);
// function to pass to the stack_a, all the items in the correct order
int		refill_a(t_stack **stack_a, t_stack **stack_b);

#endif
