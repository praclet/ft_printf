/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 00:14:02 by praclet           #+#    #+#             */
/*   Updated: 2020/11/25 00:14:04 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	length;

	length = ft_strlen(s);
	while (length >= 0 && s[length] != c)
		length--;
	if (length >= 0)
		return ((char *)s + length);
	return (NULL);
}
