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
	int				content;
	struct s_stack	*next;
}	t_stack;

/*FT_CHECK_INPUT*/
// FIRST STEP, SEE THE CHARS OF THE INPUT
size_t	check_input(char **input);

/*STACK_FUNCTIONS*/
//FUNCTION CREATES A T_STACK WITH THE VALUE OF THE PARAMETER
t_stack	*create_cont(int num);
//FUNCTION ADDS AT THE END OF THE STACK, A NEW NUMBER
void	add_num(t_stack **lst, t_stack *nlst);

#endif
