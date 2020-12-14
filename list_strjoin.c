/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 11:09:12 by praclet           #+#    #+#             */
/*   Updated: 2020/12/14 14:15:52 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "list_strjoin.h"
#include "libft/libft.h"
#include <stdlib.h>

static char	*ft_malloc_str(t_list *list)
{
	int	length;

	length = 0;
	while (list)
	{
		length += ft_strlen((char *)list->content);
		list = list->next;
	}
	return (malloc((length + 1) * sizeof(char)));
}

char		*ft_list_join(t_list *list)
{
	char	*res;
	char	*res_tmp;
	int		tmp;

	res = ft_malloc_str(list);
	res_tmp = res;
	if (res)
	{
		while (list)
		{
			if (list->content)
			{
				tmp = ft_strlen((char *)list->content);
				ft_memcpy(res, list->content, tmp);
				res += tmp;
			}
			list = list->next;
		}
		*res = 0;
	}
	return (res_tmp);
}
