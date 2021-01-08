/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 13:31:43 by praclet           #+#    #+#             */
/*   Updated: 2021/01/08 13:57:03 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"
#include "padding.h"
#include "libft/libft.h"
#include "itoa_base.h"

int		padding(t_chain *list, int len_str)
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

int		padding_di(t_chain *list, int len_str)
{
	char	*res;
	int		len;

	(void)len_str;
	len = digit_nb(list->u_arg.arg_llint, 10);
	res = malloc(sizeof(char) * len);
	if (!res)
		return (-1);
	itoa_base(list->u_arg.arg_llint, "0123456789", res);
	return (1);
}

void	padding_number_(t_chain *list, int len_str, char *res, int len)
{
	int	sgn;
	int	pos;
	int	width;
	int	prec;

	sgn = list->flags & (FLAG_SPACE | FLAG_PLUS) || list->str[0] == '-' ? 1 : 0;
	pos = 0;
	width = 0;
	prec = 0;
	if (len_str < list->precision)
	{
		prec = list->precision - len_str;
		if (list->width > list->precision + sgn)
			width = list->width - list->precision - sgn;
	}
	else
		if (list->width > len_str + sgn)
			width = list->width - len_str - sgn;
	if (list->flags & FLAG_DASH)
	{
		pos = 0;
		ft_memset(res + sgn + len_str, ' ', len - sgn - len_str);
		ft_memset(res + sgn + len_str, '0', len - sgn - len_str);
	}
	else
	{
		pos = width;
	}
	if (sgn)
	{
		if (list->flags & FLAG_SPACE)
			res[pos] = ' ';
		if (list->flags & FLAG_PLUS)
			res[pos] = '+';
		if (list->str[0] == '-')
			res[pos] = '-';
	}
}

int		padding_number(t_chain *list, int len_str)
{
	char	*res;
	char	*tmp;
	int		len;

	if (list->width <= len_str &&
		((list->str[0] == '-' && list->precision <= len_str - 1)
		|| (list->str[0] != '-' && list->precision <= len_str)))
		return (1);
	len = list->precision;
	if (list->str[0] == '-')
		len++;
	if (len <= list->width)
		len = list->width;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (-1);
	padding_number_(list, len_str, res, len);
	res[len] = 0;
	tmp = list->str;
	list->str = res;
	free(tmp);
	return (1);
}
