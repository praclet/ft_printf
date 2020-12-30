/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 13:31:43 by praclet           #+#    #+#             */
/*   Updated: 2020/12/30 10:20:13 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "padding.h"
#include "libft/libft.h"

char	*padding(char *str, int length, char pad, int left_justified)
{
	int		len_str;
	char	*res;

	if (!str || !pad || length <= 0)
		return (str);
	len_str = ft_strlen(str);
	if (length <= len_str)
		return (str);
	res = malloc(sizeof(char) * (length + 1));
	if (res)
	{
		if (left_justified)
		{
			ft_memcpy(res, str, len_str);
			ft_memset(res + len_str, pad, length - len_str);
		}
		else
		{
			ft_memset(res, pad, length - len_str);
			ft_memcpy(res + length - len_str, str, len_str);
		}
		res[length] = 0;
		free(str);
	}
	return (res);
}
