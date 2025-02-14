/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 14:19:01 by praclet           #+#    #+#             */
/*   Updated: 2021/01/10 09:40:11 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "itoa_base.h"
#include "libft/libft.h"

int			digit_unb(long long unsigned int nb, int len)
{
	int	res;

	res = 1;
	while (nb /= len)
		res++;
	return (res);
}

static int	check_base(char *base, int length)
{
	int	i;
	int j;

	if (length <= 1)
		return (0);
	i = 0;
	while (i < length)
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (j < length)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	uitoa_base_(long long unsigned int nb, char *base, char *res,
		int nb_digit)
{
	unsigned int length;

	length = ft_strlen(base);
	if (nb < length)
		*res = base[nb];
	else
	{
		uitoa_base_(nb / length, base, res, nb_digit - 1);
		uitoa_base_(nb % length, base, res + nb_digit - 1, 1);
	}
}

void		uitoa_base(long long unsigned int nbr, char *base, char *res)
{
	int		len;
	int		len_nbr;

	len = ft_strlen(base);
	if (!check_base(base, len))
		return ;
	len_nbr = digit_unb(nbr, len);
	uitoa_base_(nbr, base, res, len_nbr);
	res[len_nbr] = 0;
}
