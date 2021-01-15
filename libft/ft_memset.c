/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 00:02:38 by praclet           #+#    #+#             */
/*   Updated: 2020/11/25 00:02:40 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned char	ch;

	tmp = (unsigned char *)s;
	ch = (unsigned char)c;
	while (n--)
		*tmp++ = ch;
	return (s);
}
