/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 00:17:02 by praclet           #+#    #+#             */
/*   Updated: 2020/11/25 00:17:03 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	if (!set || !*set)
		return (0);
	while (*set && c != *set)
		set++;
	return (*set == c);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	const char	*start;
	const char	*end;
	int			len;

	if (!s1)
		return (NULL);
	len = ft_strlen(s1);
	if (len)
	{
		start = s1;
		end = s1 + len - 1;
		while (*start && is_in_set(*start, set))
			start++;
		if (start <= end)
		{
			while (is_in_set(*end, set))
				end--;
			return (ft_substr(start, 0, end - start + 1));
		}
	}
	return (ft_strdup(""));
}
