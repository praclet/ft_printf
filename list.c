/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:52:18 by praclet           #+#    #+#             */
/*   Updated: 2021/01/08 15:02:59 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "libft/libft.h"
#include "list.h"

t_chain		*new_elem(void)
{
	t_chain	*res;

	res = (t_chain *)malloc(sizeof(t_chain) * 1);
	if (res)
	{
		res->str = NULL;
		res->flags = 0;
		res->width = INT_MIN;
		res->precision = INT_MIN;
		res->modifiers = 0;
		res->conversion = 0;
		res->next = NULL;
	}
	return (res);
}

t_chain		*check_list(t_chain *elem)
{
	t_chain	*res;

	res = elem;
	while (elem)
	{
		if (elem->flags & FLAG_DASH)
			elem->flags &= ~FLAG_ZERO;
		if (elem->flags & FLAG_PLUS)
			elem->flags &= ~FLAG_SPACE;
		if (elem->conversion == 'p')
			elem->modifiers = 0;
		if ((elem->conversion == 'c' || elem->conversion == '%')
			&& elem->width < 0)
			elem->width = 1;
		if (elem->conversion == 'i')
			elem->conversion = 'd';
		if (ft_strchr("diouxX", elem->conversion))
		{
			if (elem->precision != INT_MIN)
				elem->flags &= ~FLAG_ZERO;
			if (elem->flags & FLAG_ZERO && elem->precision < elem->width)
				elem->precision = elem->width;
		}
		elem = elem->next;
	}
	return (res);
}

void		delete_elem(t_chain *elem)
{
	if (elem)
	{
		if (elem->str)
			free(elem->str);
		free(elem);
	}
}

void		delete_list(t_chain *list)
{
	t_chain	*tmp;

	while (list)
	{
		tmp = list->next;
		delete_elem(list);
		list = tmp;
	}
}

char		*list_finish(t_chain *list, int length)
{
	char	*cur;
	char	*res;
	int		len;

	res = malloc(sizeof(char) * (length + 1));
	if (!res)
		return (NULL);
	cur = res;
	while (list)
	{
		if (list->str)
		{
			if (list->conversion == 'c')
				len = list->width > 0 ? list->width : 1;
			else
				len = ft_strlen(list->str);
			ft_memcpy(cur, list->str, len);
			cur += len;
		}
		list = list->next;
	}
	*cur = 0;
	return (res);
}
