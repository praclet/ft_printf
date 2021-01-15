/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 00:15:28 by praclet           #+#    #+#             */
/*   Updated: 2020/11/25 00:15:29 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_calloc_result(long nb)
{
	int	i;

	i = 1;
	if (nb <= 0)
		i++;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return ((char *)ft_calloc(i, sizeof(char)));
}

void		ft_itoa_(long nb, char **res)
{
	if (nb < 0)
	{
		**res = '-';
		(*res)++;
		ft_itoa_(-nb, res);
	}
	else
	{
		if (nb < 10)
		{
			**res = '0' + nb;
			(*res)++;
		}
		else
		{
			ft_itoa_(nb / 10, res);
			ft_itoa_(nb % 10, res);
		}
	}
}

char		*ft_itoa(int nb)
{
	char	*res;
	char	*res_tmp;

	res = ft_calloc_result(nb);
	res_tmp = res;
	if (res)
		ft_itoa_(nb, &res);
	return (res_tmp);
}
