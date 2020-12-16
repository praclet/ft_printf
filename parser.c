/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 11:24:12 by praclet           #+#    #+#             */
/*   Updated: 2020/12/16 13:20:22 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"
#include "list.h"

int		is_in_set(char c, char *set)
{
	while (*set && *set != c)
		set++;
	return (*set == c);
}

t_list	*parse(char *str)
{
	t_list	*res;
	t_list	*last;
	t_list	*cur;
	char	*start;

	res = NULL;
	while (*str)
	{
		start = str;
		while (*str && *str != '%')
			str++;
		if (start != str)
		{
			cur = (t_list *)malloc(sizeof(t_list) * 1);
			if (!cur)
			{
				delete_list(res);
				return (NULL);
			}
			cur->str = ft_substr(start, 0, str - start);
			if (!cur->str)
			{
				free(cur);
				delete_list(res);
				return (NULL);
			}
			cur->conversion = s;
			if (!res)
				res = cur;
			else
				last->next = cur;
			last = cur;
		}
		if (*str == '%')
		{
			str++;
			cur = (t_list *)malloc(t_list);
			if (!cur)
			{
				delete_list(res);
				return (NULL);
			}
			while (is_in_set(*str, "#0- +.*"))
			{
				if (*str == '#')
					cur->flags |= FLAG_SHARP;
				if (*str == '0')
					cur->flags |= FLAG_ZERO;
				if (*str == '-')
					cur->flags |= FLAG_DASH;
				if (*str == ' ')
					cur->flags |= FLAG_SPACE;
				if (*str == '+')
					cur->flags |= FLAG_PLUS;
				if (*str == '.')
					cur->flags |= FLAG_DOT;
				if (*str == '*')
					cur->flags |= FLAG_STAR;
				str++;
			}
			if (*str >= '1' && *str <= '9')
			{
				cur->width = 0;
				while (*str >= '0' && *str <= '9')
				{
					cur->width = cur->width * 10 + *str - '0';
					str++;
				}
			}
			if (*str == '.')
			{
				*str++;
				cur->precision = 0;
				while (*str && *str >= '0' && *str <= '9')
				{
					cur->precision = cur->precision * 10 + *str - '0';
					str++;
				}
			}
			while (*str == 'h' || *str == 'l')
			{
				if (*str == 'h')
				{
					if (*(str + 1) == 'h')
					{
						cur->modifiers |= MODIFIER_HH;
						str++;
					}
					else
						cur->modifiers |= MODIFIER_H;
				}
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
			if (!res)
				res = cur;
			else
				last->next = cur;
			last = cur;
			str++;
		}
	}
	return (res);
}
