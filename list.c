/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:52:18 by praclet           #+#    #+#             */
/*   Updated: 2020/12/16 08:54:03 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "libft/libft.h"
#include "list.h"

t_list		*new_elem(void)
{
	t_list	*res;

	res = (t_list *)malloc(sizeof(t_list) * 1);
	if (res)
	{
		res->str = NULL;
		res->arg1 = NULL;
		res->arg2 = NULL;
		res->flags = 0;
		res->width = INT_MIN;
		res->precision = INT_MIN;
		res->modifiers = 0;
		res->conversion = none;
		res->next = NULL;
	}
	return (res);
}

void		check_elem(t_list *elem)
{
	if (elem->flags & FLAG_DASH)
		elem->flags &= ~FLAG_ZERO;
	if (elem->flags & FLAG_PLUS)
		elem->flags &= ~FLAG_SPACE;
}

void		delete_elem(t_list *elem)
{
	if (!elem)
		return ;
	if (elem->str)
		free(elem->str);
	if (elem->arg1)
		free(elem->arg1);
	if (elem->arg2)
		free(elem->arg2);
	free(elem);
}

void		delete_list(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list->next;
		delete_elem(list);
		list = tmp;
	}
}

static char	*malloc_str(t_list *list)
{
	int	length;

	length = 0;
	while (list)
	{
		length += ft_strlen(list->str);
		list = list->next;
	}
	return (malloc((length + 1) * sizeof(char)));
}

char		*list_finish(t_list *list)
{
	char	*cur;
	char	*res;
	int		len;
	t_list	*tmp;

	res = ft_malloc_str(list);
	if (res)
	{
		cur = res;
		while (list)
		{
			if (list->str)
			{
				len = ft_strlen(list->str);
				ft_memcpy(cur, list->str, len);
				cur += len;
			}
			tmp = list->next;
			delete_list(list);
			list = tmp;
		}
		*cur = 0;
	}
	return (res);
}
