/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 02:42:01 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/05/26 04:02:58 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*flst;
	t_list	*tmp;

	flst = ft_lstnew(f(lst->content));
	if (!flst)
		return (0);
	lst = lst->next;
	while (lst)
	{
		flst->next = lst;
		flst = ft_lstnew(f(lst->content));
		if (!flst->content)
		{
			del(dlst->content);
			free(*);
		}
		lst = lst->next;
	}
}
