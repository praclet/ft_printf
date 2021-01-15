/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 00:12:35 by praclet           #+#    #+#             */
/*   Updated: 2020/11/25 02:06:37 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	size_dest;
	unsigned int	size_src;
	unsigned int	size_tmp;

	size_tmp = size;
	size_dest = ft_strlen(dest);
	size_src = ft_strlen(src);
	if (dest && src && *src && size && size_dest < size)
	{
		dest += size_dest;
		size -= size_dest + 1;
		while (*src && size-- > 0)
			*dest++ = *src++;
		*dest = 0;
	}
	return (size_src + (size_dest > size_tmp ? size_tmp : size_dest));
}
