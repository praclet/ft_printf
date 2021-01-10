/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 11:24:12 by praclet           #+#    #+#             */
/*   Updated: 2021/01/10 15:17:45 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "parser.h"
#include "list.h"
#include "libft/libft.h"

static t_chain	*add_element(t_chain **res, t_chain **last)
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

static int		parse_text(const char **str,
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

static void		parse_flag(const char **str, t_chain *cur)
{
	while (**str && ft_strchr("#- +0", **str))
	{
		if (**str == '#')
			cur->flags |= FLAG_SHARP;
		if (**str == '-')
			cur->flags |= FLAG_DASH;
		if (**str == ' ')
			cur->flags |= FLAG_SPACE;
		if (**str == '+')
			cur->flags |= FLAG_PLUS;
		if (**str == '0')
			cur->flags |= FLAG_ZERO;
		(*str)++;
	}
}

void			parse_prec(const char **str, t_chain *cur)
{
	if (**str == '.')
	{
		(*str)++;
		cur->precision = 0;
		if (**str == '*')
		{
			cur->precision = INT_MAX;
			(*str)++;
		}
		else
			while (**str >= '0' && **str <= '9')
			{
				cur->precision = cur->precision * 10 + **str - '0';
				(*str)++;
			}
	}
}

void			parse_width_prec(const char **str, t_chain *cur)
{
	if ((**str >= '1' && **str <= '9') || **str == '*')
	{
		cur->width = 0;
		if (**str == '*')
		{
			cur->width = INT_MAX;
			(*str)++;
		}
		else
		{
			while (**str >= '0' && **str <= '9')
			{
				cur->width = cur->width * 10 + **str - '0';
				(*str)++;
			}
		}
	}
	parse_prec(str, cur);
}

void			parse_modifier_conversion(const char **str, t_chain *cur)
{
	if (**str == 'h' || **str == 'l')
	{
		if (**str == *(*str + 1))
		{
			cur->modifiers |= **str == 'h' ? MODIFIER_HH : MODIFIER_LL;
			(*str) += 2;
		}
		else
		{
			cur->modifiers |= **str == 'h' ? MODIFIER_H : MODIFIER_L;
			(*str)++;
		}
	}
	if (**str && ft_strchr("c%spdiuxXo", **str))
	{
		cur->conversion = **str;
		(*str)++;
	}
}

t_chain			*parse(const char *str)
{
	t_chain	*res;
	t_chain	*cur;
	t_chain	*last;

	if (!str)
		return (NULL);
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
