/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:37:52 by praclet           #+#    #+#             */
/*   Updated: 2020/12/26 15:40:16 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include "libft/libft.h"

static int	convert_c(t_chain *list)
{
	;
}

static int	convert_s(t_chain *list)
{
	;
}

static int	convert_p(t_chain *list)
{
	;
}

static int	convert_d(t_chain *list)
{
	;
}

static int	convert_i(t_chain *list)
{
	;
}

static int	convert_u(t_chain *list)
{
	;
}

static int	convert_o(t_chain *list)
{
	;
}

static int	convert_xx(t_chain *list)
{
	;
}

static int	convert_(t_chain *list)
{
	if (list->conversion == 'c')
		return (convert_c(list));
	if (list->conversion == 's')
		return (convert_s(list));
	if (list->conversion == 'p')
		return (convert_p(list));
	if (list->conversion == 'd')
		return (convert_d(list));
	if (list->conversion == 'i')
		return (convert_i(list));
	if (list->conversion == 'u')
		return (convert_u(list));
	if (list->conversion == 'x' || list->conversion == 'X')
		return (convert_xx(list));
	if (list->conversion == 'o')
		return (convert_o(list));
	return (0);
}

int			convert(t_chain *list)
{
	int	res;

	res = 0;
	while (list)
	{
		if (!list->str)
		{
			if (list->conversion == 'n')
				*((int *)list->u_arg.arg_ptr) = res;
			else
				res += convert_(list);
		}
		else
			res += ft_strlen(list->str);
		list = list->next;
	}
	return (res);
}
