/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:29:58 by praclet           #+#    #+#             */
/*   Updated: 2020/12/29 15:57:54 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "parser.h"
#include "arg_affectation.h"
#include "conversion.h"

int	ft_printf(const char *str, ...)
{
	t_chain	*list;
	va_list	ap;
	int		res;

	va_start(ap, str);
	list = parse(str);
	affectation(list, ap);
	res = convert(list);
	va_end(ap);
	return (res);
}
