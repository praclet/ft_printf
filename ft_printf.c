/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 14:29:58 by praclet           #+#    #+#             */
/*   Updated: 2021/01/03 09:07:20 by praclet          ###   ########lyon.fr   */
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
	int		len;
	char	*tmp;

	va_start(ap, str);
	list = parse(str);
	if (!list)
		return (-1);
	affectation(list, ap);
	va_end(ap);
	if ((len = convert(list)) < 0)
	{
		delete_list(list);
		return (-1);
	}
	tmp = list_finish(list, len);
	delete_list(list);
	if (tmp)
	{
		write(1, tmp, len);
		free(tmp);
		return (len);
	}
	return (-1);
}
