/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:29:58 by praclet           #+#    #+#             */
/*   Updated: 2020/12/23 13:03:18 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "parser.h"
#include "arg_affectation.h"

int	ft_printf(const char *str, ...)
{
	t_chain	*list;
	va_list	ap;

	list = parse(str);
	va_start(ap, str);
	affectation(list, ap);
	va_end(ap);
	return (0);
}
