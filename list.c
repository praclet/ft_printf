/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:52:18 by praclet           #+#    #+#             */
/*   Updated: 2020/12/14 18:12:00 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "ft_printf.h"
#include "element.h"

t_element	*new_element(void)
{
	t_element	*res;

	res = (t_element *)malloc(sizeof(t_element) * 1);
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
	}
	return (res);
}

void		check_element(t_element *elem)
{
	if (element->flags & FLAG_DASH)
		element->flags &= ~FLAG_ZERO;
	if (element->flags & FLAG_PLUS)
		element->flags &= ~FLAG_SPACE;
}

void		delete_element(t_element *element)
{
	if (!element)
		return ;
	if (element->str)
		free(element->str);
	if (element->arg1)
		free(element->arg1);
	if (element->arg2)
		free(element->arg2);
	free(element);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 11:09:12 by praclet           #+#    #+#             */
/*   Updated: 2020/12/14 14:15:52 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "list_strjoin.h"
#include "libft/libft.h"
#include <stdlib.h>

static char	*ft_malloc_str(t_list *list)
{
	int	length;

	length = 0;
	while (list)
	{
		length += ft_strlen((char *)list->content);
		list = list->next;
	}
	return (malloc((length + 1) * sizeof(char)));
}

char		*ft_list_join(t_list *list)
{
	char	*res;
	char	*res_tmp;
	int		tmp;

	res = ft_malloc_str(list);
	res_tmp = res;
	if (res)
	{
		while (list)
		{
			if (list->content)
			{
				tmp = ft_strlen((char *)list->content);
				ft_memcpy(res, list->content, tmp);
				res += tmp;
			}
			list = list->next;
		}
		*res = 0;
	}
	return (res_tmp);
}
