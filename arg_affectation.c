/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_affectation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 12:51:58 by praclet           #+#    #+#             */
/*   Updated: 2020/12/26 10:42:57 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <limits.h>
#include "libft/libft.h"
#include "list.h"
#include "arg_affectation.h"

static void	affectation_di(t_chain *list, va_list ap)
{
	if (!list->modifiers)
		list->u_arg.arg_llint = (int)va_arg(ap, int);
	if (list->modifiers & MODIFIER_L)
		list->u_arg.arg_llint = (long int)va_arg(ap, long int);
	if (list->modifiers & MODIFIER_LL)
		list->u_arg.arg_llint = (long long int)va_arg(ap, long long int);
	if (list->modifiers & MODIFIER_H)
		list->u_arg.arg_llint = (short int)va_arg(ap, int);
	if (list->modifiers & MODIFIER_HH)
		list->u_arg.arg_llint = (signed char)va_arg(ap, int);
}

static void	affectation_uoxx(t_chain *list, va_list ap)
{
	if (!list->modifiers)
		list->u_arg.arg_ullint = (unsigned int)va_arg(ap, unsigned int);
	if (list->modifiers & MODIFIER_L)
		list->u_arg.arg_ullint =
			(unsigned long int)va_arg(ap, unsigned long int);
	if (list->modifiers & MODIFIER_LL)
		list->u_arg.arg_ullint =
			(unsigned long long int)va_arg(ap, unsigned long long int);
	if (list->modifiers & MODIFIER_H)
		list->u_arg.arg_ullint = (unsigned short int)va_arg(ap, int);
	if (list->modifiers & MODIFIER_HH)
		list->u_arg.arg_ullint = (unsigned char)va_arg(ap, int);
}

static void	affectation_star(t_chain *list, va_list ap)
{
	if (list->width == INT_MAX)
		list->width = (int)va_arg(ap, int);
	if (list->precision == INT_MAX)
		list->precision = (int)va_arg(ap, int);
}

void		affectation(t_chain *list, va_list ap)
{
	while (list)
	{
		if (!list->str)
		{
			affectation_star(list, ap);
			if (ft_strchr("di", list->conversion))
				affectation_di(list, ap);
			if (ft_strchr("uoxX", list->conversion))
				affectation_uoxx(list, ap);
			if (ft_strchr("c", list->conversion))
			{
				if (!list->modifiers)
					list->u_arg.arg_int = (int)va_arg(ap, int);
				if (list->modifiers & MODIFIER_L)
					list->u_arg.arg_wint_t = (wint_t)va_arg(ap, wint_t);
			}
			if (ft_strchr("fFeEgGaA", list->conversion))
				list->u_arg.arg_double = (double)va_arg(ap, double);
			if (ft_strchr("spn", list->conversion))
				list->u_arg.arg_ptr = (void *)va_arg(ap, void *);
		}
		list = list->next;
	}
}
