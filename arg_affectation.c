/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_affectation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 12:51:58 by praclet           #+#    #+#             */
/*   Updated: 2020/12/23 12:49:21 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include "list.h"
#include "arg_affectation.h"

void	affectation(t_chain	*list, va_list ap)
{
	while (list)
	{
		if (ft_strchr("di", list->conversion))
		{
			if (list->modifiers & MODIFIER_L)
				list->u_arg.arg_llint=(long int)va_arg(ap, long int);
			if (list->modifiers & MODIFIER_LL)
				list->u_arg.arg_llint=(long long int)va_arg(ap, long long int);
			if (list->modifiers & MODIFIER_H)
				list->u_arg.arg_llint=(short int)va_arg(ap, int);
			if (list->modifiers & MODIFIER_HH)
				list->u_arg.arg_llint=(signed char)va_arg(ap, int);
			if (!list->modifiers)
				list->u_arg.arg_llint=(int)va_arg(ap, int);
		}
		list = list->next;
	}
}
