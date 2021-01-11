/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 13:31:43 by praclet           #+#    #+#             */
/*   Updated: 2021/01/11 11:38:08 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "list.h"
#include "conversion2.h"
#include "libft/libft.h"
#include "itoa_base.h"

static void	base(t_chain *list, t_carac *carac)
{
	if (list->conversion == 'd' || list->conversion == 'i'
			|| list->conversion == 'u')
		carac->base = "0123456789";
	if (list->conversion == 'o')
		carac->base = "01234567";
	if (list->conversion == 'x' || list->conversion == 'p')
		carac->base = "0123456789abcdef";
	if (list->conversion == 'X')
		carac->base = "0123456789ABCDEF";
	if (list->precision == 0 && list->u_arg.arg_ullint == 0)
		carac->len = 0;
	else
		carac->len = digit_unb(list->u_arg.arg_ullint, ft_strlen(carac->base));
	carac->sgn = !!(list->flags & (FLAG_SPACE | FLAG_PLUS | FLAG_NEG));
	carac->zero_x = (ft_strchr("xX", list->conversion)
		&& (list->flags & FLAG_SHARP) && list->u_arg.arg_ullint)
		|| list->conversion == 'p';
	if (list->width > 0 && (list->flags & FLAG_ZERO
			&& (list->precision == INT_MIN
			|| list->precision - carac->zero_x < list->width)))
		list->precision = list->width - carac->sgn - carac->zero_x * 2;
}

static void	allocation(t_chain *list, t_carac *carac)
{
	if (list->precision > list->width)
	{
		if (list->precision > carac->len)
			carac->len_str = list->precision;
		else
			carac->len_str = carac->len;
		carac->len_str += carac->sgn + carac->zero_x * 2;
	}
	else
	{
		if (list->width > carac->len + carac->sgn + carac->zero_x * 2)
			carac->len_str = list->width;
		else
			carac->len_str = carac->len + carac->sgn + carac->zero_x * 2;
	}
	list->str = malloc(sizeof(char) * (carac->len_str + 1));
}

static void	calculation(t_chain *list, t_carac *carac)
{
	carac->pos = 0;
	carac->width = 0;
	carac->prec = 0;
	if (carac->len < list->precision)
	{
		carac->prec = list->precision - carac->len;
		if (list->width > list->precision + carac->sgn + carac->zero_x * 2)
			carac->width = list->width - list->precision
				- carac->sgn - carac->zero_x * 2;
	}
	else
	{
		if (list->width > carac->len + carac->sgn + carac->zero_x * 2)
			carac->width = list->width
				- carac->len - carac->sgn - carac->zero_x * 2;
	}
}

static void	padding_number(t_chain *list, t_carac *carac)
{
	if (list->flags & FLAG_DASH)
	{
		ft_memset(list->str + carac->sgn + carac->zero_x * 2, '0', carac->prec);
		if (list->precision || list->u_arg.arg_ullint)
			uitoa_base(list->u_arg.arg_ullint, carac->base,
				list->str + carac->zero_x * 2 + carac->sgn + carac->prec);
		ft_memset(list->str + carac->zero_x * 2 + carac->sgn + carac->prec
				+ carac->len, ' ', carac->width);
	}
	else
	{
		carac->pos = carac->width;
		ft_memset(list->str, ' ', carac->width);
		ft_memset(list->str + carac->zero_x * 2 + carac->sgn + carac->width,
			'0', carac->prec);
		if (list->precision || list->u_arg.arg_ullint)
			uitoa_base(list->u_arg.arg_ullint, carac->base,
				list->str + carac->zero_x * 2 + carac->sgn + carac->width
				+ carac->prec);
	}
}

int			convert_number_(t_chain *list)
{
	t_carac	carac;

	base(list, &carac);
	allocation(list, &carac);
	if (!list->str)
		return (-1);
	list->str[carac.len_str] = 0;
	calculation(list, &carac);
	padding_number(list, &carac);
	if (carac.zero_x)
	{
		list->str[carac.pos] = '0';
		list->str[carac.pos + 1] = list->conversion == 'p'
			? 'x' : list->conversion;
	}
	if (carac.sgn)
	{
		if (list->flags & FLAG_SPACE)
			list->str[carac.pos] = ' ';
		if (list->flags & FLAG_PLUS)
			list->str[carac.pos] = '+';
		if (list->flags & FLAG_NEG)
			list->str[carac.pos] = '-';
	}
	return (1);
}
