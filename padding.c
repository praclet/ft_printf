/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 13:31:43 by praclet           #+#    #+#             */
/*   Updated: 2021/01/10 09:46:43 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "list.h"
#include "padding.h"
#include "libft/libft.h"
#include "itoa_base.h"

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

int	padding_di(t_chain *list)
{
	char	*res;
	int		sgn;
	int		pos;
	int		width;
	int		prec;
	int		len;
	int		len_str;

	len = digit_nb(list->u_arg.arg_llint, 10);
	if (list->precision > list->width)
	{
		if (list->precision > len)
			len_str = list->precision;
		else
			len_str = len;
	}
	else
	{
		if (list->width > len)
			len_str = list->width;
		else
			len_str = len;
	}
	sgn = list->flags & (FLAG_SPACE | FLAG_PLUS | FLAG_NEG);
	len_str += sgn;
	res = malloc(sizeof(char) * (len_str + 1));
	list->str = res;
	if (!res)
		return (-1);
	res[len_str] = 0;
	pos = 0;
	width = 0;
	prec = 0;
	if (len - sgn < list->precision)
	{
		prec = list->precision - len + sgn;
		if (list->width > list->precision + sgn)
			width = list->width - list->precision - sgn;
	}
	else
	{
		if (list->width > len + sgn)
			width = list->width - len - sgn;
	}
	if (list->flags & FLAG_DASH)
	{
		ft_memset(res + sgn, '0', prec);
		itoa_base(list->u_arg.arg_ullint, "0123456789", res + sgn + prec);
		ft_memset(res + sgn + prec + len, ' ', width);
	}
	else
	{
		pos = width;
		ft_memset(res, ' ', width);
		ft_memset(res + sgn + width, '0', prec);
		itoa_base(list->u_arg.arg_ullint, "0123456789", res + sgn + width + prec);
	}
	if (sgn)
	{
		if (list->flags & FLAG_SPACE)
			res[pos] = ' ';
		if (list->flags & FLAG_PLUS)
			res[pos] = '+';
		if (list->flags & FLAG_NEG)
			res[pos] = '-';
	}
	return (1);
}
