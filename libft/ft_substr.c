/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 00:17:12 by praclet           #+#    #+#             */
/*   Updated: 2020/11/25 00:17:13 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	char	*res_tmp;

	if (!s)
		return (NULL);
	res = (char *)ft_calloc(len + 1, sizeof(char));
	res_tmp = res;
	if (res)
	{
		while (*s && start)
		{
			s++;
			start--;
		}
		while (*s && len--)
			*res++ = *s++;
	}
	return (res_tmp);
}
