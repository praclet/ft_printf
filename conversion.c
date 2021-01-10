/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:37:52 by praclet           #+#    #+#             */
/*   Updated: 2021/01/10 11:04:16 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include "list.h"
#include "padding.h"
#include "libft/libft.h"
#include "itoa_base.h"

static int	convert_c(t_chain *list)
{
	list->str = malloc(sizeof(char) * 2);
	if (!list->str)
		return (-1);
	list->str[0] = (char)list->u_arg.arg_int;
	list->str[1] = 0;
	if (padding(list, 1) < 0)
		return (-1);
	return (list->width);
}

static int	convert_s(t_chain *list)
{
	char	*tmp;
	int		len;

	list->str = list->u_arg.arg_ptr
		? ft_strdup(list->u_arg.arg_ptr) : ft_strdup("(null)");
	if (!list->str)
		return (-1);
	len = ft_strlen(list->str);
	if (list->precision != INT_MIN && list->precision < len)
	{
		tmp = list->str;
		list->str = ft_substr(list->str, 0, list->precision);
		free(tmp);
		if (!list->str)
			return (-1);
		len = ft_strlen(list->str);
	}
	if (padding(list, len) < 0)
		return (-1);
	else
		len = ft_strlen(list->str);
	return (len);
}

static int	convert_p(t_chain *list)
{
	(void)list;
	return (0);
}

static int	convert_diu(t_chain *list)
{
	if (padding_number(list) < 0)
		return (-1);
	return (ft_strlen(list->str));
}

static int	convert_o(t_chain *list)
{
	(void)list;
	return (0);
}

static int	convert_xx(t_chain *list)
{
	(void)list;
	return (0);
}

static int	convert_(t_chain *list)
{
	if (list->conversion == 'c')
		return (convert_c(list));
	if (list->conversion == 's')
		return (convert_s(list));
	if (list->conversion == 'p')
		return (convert_p(list));
	if (list->conversion == 'd' || list->conversion == 'i'
			|| list->conversion == 'u')
		return (convert_diu(list));
	if (list->conversion == 'x' || list->conversion == 'X')
		return (convert_xx(list));
	if (list->conversion == 'o')
		return (convert_o(list));
	return (0);
}

int			convert(t_chain *list)
{
	int	res;
	int	tmp;

	res = 0;
	while (list)
	{
		if (!list->str)
		{
			if (list->conversion == 'n')
				*((int *)list->u_arg.arg_ptr) = res;
			else
			{
				tmp = convert_(list);
				if (tmp >= 0)
					res += tmp;
				else
					return (-1);
			}
		}
		else
			res += ft_strlen(list->str);
		list = list->next;
	}
	return (res);
}
