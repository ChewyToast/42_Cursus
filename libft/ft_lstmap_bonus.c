/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 02:42:01 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/05/26 10:39:58 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*flst;
	t_list	*tmp;

	if (!lst)
		return (0);
	flst = ft_lstnew(f(lst->content));
	if (!flst)
		return (0);
	tmp = flst;
	lst = lst->next;
	while (lst)
	{
		tmp->next = ft_lstnew(f(lst->content));
		if (!(tmp->next))
		{
			ft_lstclear(&flst, del);
			return (0);
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	return (flst);
}
