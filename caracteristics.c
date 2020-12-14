/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caracteristics.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 10:52:18 by praclet           #+#    #+#             */
/*   Updated: 2020/12/14 13:45:58 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "ft_printf.h"
#include "caracteristics.h"

t_caracteristics	*new_caracteristics()
{
	t_caracteristics	*res;

	res = malloc(sizeof(t_caracteristics) * 1);
	if (res)
	{
		res->flags = 0;
		res->width = INT_MIN
		res->precision = INT_MIN;
		res->modifiers = 0;
		res->conversion = none;
	}
	return (res);
}

void check_caracteristics(t_caracteristics *elem)
{
	if (elem->flags & FLAG_DASH)
		elem->flags &= ~FLAG_ZERO;
	if (elem->flags & FLAG_PLUS)
		elem->flags &= ~FLAG_SPACE;
}
