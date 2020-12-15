/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:52:18 by praclet           #+#    #+#             */
/*   Updated: 2020/12/15 09:34:11 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "libft/libft.h"
#include "ft_printf.h"
#include "list.h"

t_list		*new_list(void)
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

void		check_list(t_list *list)
{
	if (list->flags & FLAG_DASH)
		list->flags &= ~FLAG_ZERO;
	if (list->flags & FLAG_PLUS)
		list->flags &= ~FLAG_SPACE;
}

void		delete_list(t_list *list)
{
	if (!list)
		return ;
	if (list->str)
		free(list->str);
	if (list->arg1)
		free(list->arg1);
	if (list->arg2)
		free(list->arg2);
	free(list);
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
