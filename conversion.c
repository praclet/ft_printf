/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:37:52 by praclet           #+#    #+#             */
/*   Updated: 2020/12/30 11:43:15 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "list.h"
#include "padding.h"
#include "libft/libft.h"

static int	convert_c(t_chain *list)
{
	list->str = malloc(sizeof(char) * 2);
	if (!list->str)
		return (-1);
	list->str[0] = (char)list->u_arg.arg_int;
	list->str[1] = 0;
	if (list->width > 1)
		list->str = padding(list->str, list->width,
			list->flags & FLAG_ZERO ? '0' : ' ', list->flags & FLAG_DASH);
	return (list->width);
}

static int	convert_s(t_chain *list)
{
	char	*tmp;
	int		len;

	if (list->u_arg.arg_ptr)
		list->str = ft_strdup(list->u_arg.arg_ptr);
	else
		list->str = ft_strdup("(null)");
	len = ft_strlen(list->str);
	if (list->precision != INT_MIN && list->precision < len)
	{
		tmp = list->str;
		list->str = ft_substr(list->str, 0, list->precision);
		free(tmp);
		len = ft_strlen(list->str);
	}
	if (len < list->width)
	{
		list->str = padding(list->str, list->width,
			list->flags & FLAG_ZERO ? '0' : ' ', list->flags & FLAG_DASH);
		return (list->width);
	}
	return (len);
}

static int	convert_p(t_chain *list)
{
	(void)list;
	return (0);
}

static int	convert_d(t_chain *list)
{
	(void)list;
	return (0);
}

static int	convert_i(t_chain *list)
{
	(void)list;
	return (0);
}

static int	convert_u(t_chain *list)
{
	(void)list;
	return (0);
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
