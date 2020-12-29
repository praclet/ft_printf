/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:29:58 by praclet           #+#    #+#             */
/*   Updated: 2020/12/29 17:56:01 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "list.h"
#include "ft_printf.h"
#include "parser.h"
#include "arg_affectation.h"
#include "conversion.h"

int	ft_printf(const char *str, ...)
{
	t_chain	*list;
	va_list	ap;
	int		res;
	char	*tmp;

	va_start(ap, str);
	list = parse(str);
	if (!list)
		return (-1);
	affectation(list, ap);
	va_end(ap);
	if ((res = convert(list)) < 0)
	{
		delete_list(list);
		return (-1);
	}
	tmp = list_finish(list, res);
	delete_list(list);
	if (tmp)
	{
		write(1, tmp, res);
		free(tmp);
		return (res);
	}
	return (-1);
}
