/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 14:19:01 by praclet           #+#    #+#             */
/*   Updated: 2020/12/27 11:13:36 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "libft/libft.h"

static int		digit_nb(long long int nb, int len)
{
	int	res;

	res = nb <= 0 ? 1 : 0;
	while (nb /= len)
		res++;
	return (res);
}

static int		check_base(char *base, int length)
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

static void		itoa_base_(long nb, char *base, char *res, int nb_digit)
{
	int length;

	length = ft_strlen(base);
	if (nb < 0)
	{
		*res = '-';
		itoa_base_(-(nb / length), base, res + 1, nb_digit - 1);
		itoa_base_(-(nb % length), base, res + nb_digit - 1, 1);
	}
	else
	{
		if (nb < length)
			*res = base[nb];
		else
		{
			itoa_base_(nb / length, base, res, nb_digit);
			itoa_base_(nb % length, base, res + nb_digit - 1, 1);
		}
	}
}

char			*itoa_base(long long int nbr, char *base)
{
	int		length;
	int		nb_digit;
	char	*res;

	length = ft_strlen(base);
	if (check_base(base, length))
	{
		nb_digit = digit_nb(nbr, length);
		res = (char *)malloc(sizeof(char) * nb_digit);
		if (!res)
			return (NULL);
		itoa_base_(nbr, base, res, nb_digit);
		return (res);
	}
	return (NULL);
}
