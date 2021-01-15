/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 00:13:45 by praclet           #+#    #+#             */
/*   Updated: 2020/11/25 00:13:47 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnstr_(const char *haystack, const char *needle, size_t len)
{
	const char	*ahead;
	const char	*ahead_tmp;
	const char	*to_find;
	int			length;

	length = len;
	while (*haystack && length)
	{
		ahead = haystack;
		ahead_tmp = ahead;
		to_find = needle;
		while (*ahead && *to_find && ahead - ahead_tmp <= length
			&& *ahead == *to_find)
		{
			ahead++;
			to_find++;
		}
		if (!*to_find)
			return ((char *)ahead_tmp);
		haystack++;
		length--;
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (!*needle)
		return ((char *)haystack);
	if (!*haystack)
		return (NULL);
	return (ft_strnstr_(haystack, needle, len));
}
