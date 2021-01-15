/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 00:18:56 by praclet           #+#    #+#             */
/*   Updated: 2020/11/25 00:18:58 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (del)
		while (*lst)
		{
			if ((*lst)->content)
				(*del)((*lst)->content);
			tmp = *lst;
			*lst = (*lst)->next;
			free(tmp);
		}
}
