/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 00:02:23 by praclet           #+#    #+#             */
/*   Updated: 2020/11/25 00:02:25 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t n)
{
	char		*dst;
	const char	*src;

	dst = (char *)dest;
	src = (const char *)source;
	if (n && src != dst)
	{
		if (src > dst)
			while (n--)
				*dst++ = *src++;
		else
		{
			dst += n - 1;
			src += n - 1;
			while (n--)
				*dst-- = *src--;
		}
	}
	return (dest);
}
