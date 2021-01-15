/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 00:13:15 by praclet           #+#    #+#             */
/*   Updated: 2020/11/25 00:13:17 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned char	*uc1;
	unsigned char	*uc2;

	if (!n)
		return (0);
	uc1 = (unsigned char *)s1;
	uc2 = (unsigned char *)s2;
	n--;
	while (*uc1 && *uc2 && n)
	{
		if (*uc1 != *uc2)
			return (*uc1 - *uc2);
		uc1++;
		uc2++;
		n--;
	}
	return (*uc1 - *uc2);
}
