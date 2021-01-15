/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 23:59:58 by praclet           #+#    #+#             */
/*   Updated: 2020/11/25 00:00:01 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	length;
	void	*res;

	length = nmemb * size;
	res = NULL;
	if (length)
	{
		if (length / size == nmemb)
		{
			res = malloc(length);
			if (res)
				ft_bzero(res, length);
		}
	}
	else
		res = malloc(0);
	return (res);
}
