/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c     		                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cruiz-de <cruiz-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:43:58 by cruiz-de          #+#    #+#             */
/*   Updated: 2021/05/06 20:04:01 by cruiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*start;

	if (!lst || !f)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	start = new;
	while (lst->next)
	{
		lst = lst->next;
		new->next = ft_lstnew(f(lst->content));
		if (!new->next)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		new = new->next;
	}
	new->next = NULL;
	return (start);
}
