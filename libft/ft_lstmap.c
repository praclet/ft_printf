/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 22:03:50 by praclet           #+#    #+#             */
/*   Updated: 2020/11/24 06:34:31 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*cur;
	t_list	*last;

	if (!lst || !f)
		return (NULL);
	res = NULL;
	cur = NULL;
	last = NULL;
	while (lst)
	{
		cur = ft_lstnew((*f)(lst->content));
		if (!cur)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		if (last)
			last->next = cur;
		else
			res = cur;
		last = cur;
		lst = lst->next;
	}
	return (res);
}
