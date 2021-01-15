/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 00:16:40 by praclet           #+#    #+#             */
/*   Updated: 2020/11/25 00:16:42 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		len1;
	int		len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)ft_calloc(len1 + len2 + 1, sizeof(char));
	if (res)
	{
		ft_memcpy(res, s1, len1);
		ft_memcpy(res + len1, s2, len2);
	}
	return (res);
}
