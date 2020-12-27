/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 13:31:43 by praclet           #+#    #+#             */
/*   Updated: 2020/12/27 17:18:25 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "padding.h"
#include "libft/libft.h"

char	*padding(char *str, int length, char pad, int right_justified)
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
		if (right_justified)
		{
			ft_memset(res, pad, length - len_str);
			ft_memcpy(res + length - len_str, str, len_str);
		}
		else
		{
			ft_memcpy(res, str, len_str);
			ft_memset(res + len_str, pad, length - len_str);
		}
		res[length] = 0;
		free(str);
	}
	return (res);
}
