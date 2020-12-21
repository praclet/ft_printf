/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:52:18 by praclet           #+#    #+#             */
/*   Updated: 2020/12/21 09:34:31 by praclet          ###   ########lyon.fr   */
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
		res->arg1 = NULL;
		res->arg2 = NULL;
		res->flags = 0;
		res->width = INT_MIN;
		res->precision = INT_MIN;
		res->modifiers = 0;
		res->conversion = '\0';
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
		if (elem->arg1)
			free(elem->arg1);
		if (elem->arg2)
			free(elem->arg2);
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

static char	*malloc_str(t_chain *list)
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

char		*list_finish(t_chain *list)
{
	char	*cur;
	char	*res;
	int		len;
	t_chain	*tmp;

	res = malloc_str(list);
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
