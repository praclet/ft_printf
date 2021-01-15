/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 00:15:11 by praclet           #+#    #+#             */
/*   Updated: 2020/11/26 06:17:49 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	len;

	len = ft_strlen(src);
	if (dest && src && size)
	{
		size--;
		while (*src && size--)
			*dest++ = *src++;
		*dest = 0;
	}
	return (src ? len : 0);
}
