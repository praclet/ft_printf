/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 13:31:43 by praclet           #+#    #+#             */
/*   Updated: 2021/01/05 17:19:10 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"
#include "padding.h"
#include "libft/libft.h"

int	padding(t_chain *list, int len_str)
{
	char	*res;
	char	pad;

	if (list->width <= len_str)
		return (1);
	res = malloc(sizeof(char) * (list->width + 1));
	if (!res)
		return (-1);
	pad = list->flags & FLAG_ZERO ? '0' : ' ';
	if (list->flags & FLAG_DASH)
	{
		ft_memcpy(res, list->str, len_str);
		ft_memset(res + len_str, pad, list->width - len_str);
	}
	else
	{
		ft_memset(res, pad, list->width - len_str);
		ft_memcpy(res + list->width - len_str, list->str, len_str);
	}
	res[list->width] = 0;
	free(list->str);
	list->str = res;
	return (1);
}

int	padding_di(t_chain *list, int len_str)
{
	(void)list;
	(void)len_str;
	return (1);
}


int	padding_number(t_chain *list, int len_str)
{
	char	*str;
	int		len;

	str = list->str;
	if (list->width <= len_str && 
			((list->str[0] == '-' && list->precision <= len_str - 1)
			|| (list->str[0] != '-' && list->precision <= len_str)))
		return (1);
	if (list->str[0] == '-')
	{
		str++;
		len_str--;
	}
	len = list->precision;
	if (list->str[0] == '-')
		len++;
	if (len <= list->width)
		len = list->width;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (-1);
	if ()
	{
		;
	}
	else
	{
		;
	}
	return (1);
}
