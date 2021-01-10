/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 13:31:43 by praclet           #+#    #+#             */
/*   Updated: 2021/01/10 16:34:10 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "list.h"
#include "padding.h"
#include "libft/libft.h"
#include "itoa_base.h"

int	padding(t_chain *list, int len_str)
{
	char	*res;
	char	pad;

	if (list->width <= len_str)
		return (1);
	res = malloc(sizeof(char) * (list->width + 1));
	if (!res)
		return (-1);
	pad = list->flags & FLAG_ZERO ? '0' : ' ';
	if (list->flags & FLAG_DASH)
	{
		ft_memcpy(res, list->str, len_str);
		ft_memset(res + len_str, pad, list->width - len_str);
	}
	else
	{
		ft_memset(res, pad, list->width - len_str);
		ft_memcpy(res + list->width - len_str, list->str, len_str);
	}
	res[list->width] = 0;
	free(list->str);
	list->str = res;
	return (1);
}
