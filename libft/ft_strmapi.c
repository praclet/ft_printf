/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 00:16:52 by praclet           #+#    #+#             */
/*   Updated: 2020/11/25 00:16:53 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	res = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (res)
	{
		i = 0;
		while (s[i])
		{
			res[i] = (*f)(i, s[i]);
			i++;
		}
	}
	return (res);
}
