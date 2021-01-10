/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 13:31:43 by praclet           #+#    #+#             */
/*   Updated: 2021/01/10 15:56:21 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
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

int	padding_number(t_chain *list)
{
	char	*res;
	int		sgn;
	int		zero_x;
	int		pos;
	int		width;
	int		prec;
	int		len;
	int		len_str;
	char	*base;

	if (list->conversion == 'd' || list->conversion == 'i'
			|| list->conversion == 'u')
		base = "0123456789";
	if (list->conversion == 'o')
		base = "01234567";
	if (list->conversion == 'x' || list->conversion == 'p')
		base = "0123456789abcdef";
	if (list->conversion == 'X')
		base = "0123456789ABCDEF";
	if (list->precision == 0 && list->u_arg.arg_ullint == 0)
		len = 0;
	else
		len = digit_unb(list->u_arg.arg_ullint, ft_strlen(base));
	sgn = !!(list->flags & (FLAG_SPACE | FLAG_PLUS | FLAG_NEG));
	zero_x = (ft_strchr("xX", list->conversion) && (list->flags & FLAG_SHARP)
			&& list->u_arg.arg_ullint) || list->conversion == 'p';
	if (list->flags & FLAG_ZERO &&
		(list->precision == INT_MIN || list->precision - zero_x < list->width))
		list->precision = list->width - sgn - zero_x * 2;
	if (list->precision > list->width)
	{
		if (list->precision > len)
			len_str = list->precision;
		else
			len_str = len;
		len_str += sgn + zero_x * 2;
	}
	else
	{
		if (list->width > len + sgn + zero_x * 2)
			len_str = list->width;
		else
			len_str = len + sgn + zero_x * 2;
	}
	res = malloc(sizeof(char) * (len_str + 1));
	list->str = res;
	if (!res)
		return (-1);
	res[len_str] = 0;
	pos = 0;
	width = 0;
	prec = 0;
	if (len < list->precision)
	{
		prec = list->precision - len;
		if (list->width > list->precision + sgn + zero_x * 2)
			width = list->width - list->precision - sgn - zero_x * 2;
	}
	else
	{
		if (list->width > len + sgn + zero_x * 2)
			width = list->width - len - sgn - zero_x * 2;
	}
	if (list->flags & FLAG_DASH)
	{
		ft_memset(res + sgn + zero_x * 2, '0', prec);
		if (list->u_arg.arg_ullint == 0 && list->precision == 0)
			res[sgn + zero_x * 2 + prec] = list->width > 0 ? ' ' : 0;
		else
			uitoa_base(list->u_arg.arg_ullint, base,
				res + zero_x * 2 + sgn + prec);
		ft_memset(res + zero_x * 2 + sgn + prec + len, ' ', width);
	}
	else
	{
		pos = width;
		ft_memset(res, ' ', width);
		ft_memset(res + zero_x * 2 + sgn + width, '0', prec);
		if (list->u_arg.arg_ullint == 0 && list->precision == 0)
			res[sgn + zero_x * 2 + width + prec] = list->width > 0 ? ' ' : 0;
		else
			uitoa_base(list->u_arg.arg_ullint, base,
					res + zero_x * 2 + sgn + width + prec);
	}
	if (zero_x)
	{
		res[pos] = '0';
		if (list->conversion == 'p')
			res[pos + 1] = 'x';
		else
			res[pos + 1] = list->conversion;
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
