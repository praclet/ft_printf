/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 11:24:12 by praclet           #+#    #+#             */
/*   Updated: 2020/12/16 09:52:36 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parser.h"
#include "list.h"

t_list	*parse(char *str)
{
	t_list	*res;
	t_list	*last;
	t_list	*tmp;
	char	*start;

	res = NULL;
	last = NULL;
	while (*str)
	{
		start = str;
		while (*str && *str != '%')
			str++;
		if (start != str)
		{
			tmp = (t_list *)malloc(sizeof(t_list));
			if (!tmp)
			{
				delete_list(res);
				return (NULL);
			}
			tmp->str = ft_substr(start, 0, str - start);
			if (!tmp->str)
			{
				free(tmp);
				delete_list(res);
				return (NULL);
			}
			tmp->conversion = s;
			if (!res)
				res = tmp;
			else
				last->next = tmp;
			last = tmp;
		}
		str++;
	}
	return (res);
}
