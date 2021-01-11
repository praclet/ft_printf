/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 11:24:12 by praclet           #+#    #+#             */
/*   Updated: 2021/01/11 12:28:20 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "parser2.h"
#include "list.h"
#include "libft/libft.h"

t_chain	*add_element(t_chain **res, t_chain **last)
{
	t_chain	*cur;

	cur = new_elem();
	if (!cur)
	{
		delete_list(*res);
		*res = NULL;
		*last = NULL;
	}
	else
	{
		if (*res)
			(*last)->next = cur;
		else
			*res = cur;
		*last = cur;
	}
	return (cur);
}

int		parse_text(const char **str,
	t_chain **res, t_chain **cur, t_chain **last)
{
	const char	*start;

	if (!str || !*str || !res || !cur || !last)
		return (0);
	start = *str;
	while (**str && **str != '%')
		(*str)++;
	if (start != *str)
	{
		*cur = add_element(res, last);
		if (*cur)
			(*cur)->str = ft_substr(start, 0, *str - start);
		if (!*cur || !(*cur)->str)
		{
			delete_list(*res);
			*res = NULL;
			*cur = NULL;
			*last = NULL;
			return (0);
		}
	}
	return (1);
}

t_chain			*parse_(const char *str)
{
	t_chain	*res;
	t_chain	*cur;
	t_chain	*last;

	res = NULL;
	cur = NULL;
	last = NULL;
	while (*str)
	{
		if (!parse_text(&str, &res, &cur, &last))
			return (NULL);
		if (*str == '%')
		{
			str++;
			cur = add_element(&res, &last);
			if (!cur)
				return (NULL);
			parse_flag(&str, cur);
			parse_width_prec(&str, cur);
			parse_modifier_conversion(&str, cur);
		}
	}
	return (res);
}
