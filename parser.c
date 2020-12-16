/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 11:24:12 by praclet           #+#    #+#             */
/*   Updated: 2020/12/16 17:44:00 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"
#include "list.h"
#include "libft/libft.h"

static int		is_in_set(char c, char *set)
{
	while (*set && *set != c)
		set++;
	return (*set == c);
}

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

static int		parse_text(char **str,
	t_chain **res, t_chain **cur, t_chain **last)
{
	char	*start;

	if (!str || !res || !cur || !last)
		return (0);
	start = *str;
	while (**str && **str != '%')
		(*str)++;
	if (start != *str)
	{
		*cur = add_element(res, last);
		if (!(*cur))
			return (0);
		(*cur)->str = ft_substr(start, 0, *str - start);
		if (!(*cur)->str)
		{
			delete_list(*res);
			*res = NULL;
			*cur = NULL;
			*last = NULL;
			return (0);
		}
		(*cur)->conversion = s;
	}
	return (1);
}

static void		parse_flag(char **str, t_chain *cur)
{
	while (is_in_set(**str, "#0- +.*"))
	{
		if (**str == '#')
			cur->flags |= FLAG_SHARP;
		if (**str == '0')
			cur->flags |= FLAG_ZERO;
		if (**str == '-')
			cur->flags |= FLAG_DASH;
		if (**str == ' ')
			cur->flags |= FLAG_SPACE;
		if (**str == '+')
			cur->flags |= FLAG_PLUS;
		if (**str == '.')
			cur->flags |= FLAG_DOT;
		if (**str == '*')
			cur->flags |= FLAG_STAR;
		(*str)++;
	}
}

void	parse_widt_prec(char **str, t_chain *cur)
{
	if (**str >= '1' && **str <= '9')
	{
		cur->width = 0;
		while (**str >= '0' && **str <= '9')
		{
			cur->width = cur->width * 10 + **str - '0';
			(*str)++;
		}
	}
	if (**str == '.')
	{
		(*str)++;
		cur->precision = 0;
		while (**str && **str >= '0' && **str <= '9')
		{
			cur->precision = cur->precision * 10 + **str - '0';
			(*str)++;
		}
	}
}

t_chain			*parse(char *str)
{
	t_chain	*res;
	t_chain	*cur;
	t_chain	*last;

	res = NULL;
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
			parse_widt_prec(&str, cur);
			while (*str == 'h' || *str == 'l')
			{
				if (*str == 'h')
					if (*(str + 1) == 'h')
					{
						cur->modifiers |= MODIFIER_HH;
						str++;
					}
					else
						cur->modifiers |= MODIFIER_H;
				else
				{
					if (*str == 'l')
					{
						if (*(str + 1) == 'l')
						{
							cur->modifiers |= MODIFIER_LL;
							str++;
						}
						else
							cur->modifiers |= MODIFIER_L;
					}
				}
				str++;
			}
			cur->conversion = *str;
			str++;
		}
	}
	return (res);
}
