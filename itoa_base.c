/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 14:19:01 by praclet           #+#    #+#             */
/*   Updated: 2021/01/03 15:54:12 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "libft/libft.h"

static int		digit_nb(long long unsigned int nb, int len)
{
	int	res;

	res = 1;
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

static void		uitoa_base_(long long unsigned int nb, char *base, char *res,
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

char			*uitoa_base(long long unsigned int nbr, char *base)
{
	char	*res;
	int		len;
	int		len_nbr;

	len = ft_strlen(base);
	if (!check_base(base, len))
		return (NULL);
	len_nbr = digit_nb(nbr, len);
	res = malloc(sizeof(char) * (len_nbr + 1));
	if (res)
	{
		uitoa_base_(nbr, base, res, len_nbr);
		res[len] = 0;
	}
	return (res);
}

char			*itoa_base(long long int nbr, char *base)
{
	char					*res;
	int						len;
	int						len_nbr;
	long long unsigned int	tmp;

	len = ft_strlen(base);
	if (!check_base(base, len))
		return (NULL);
	tmp = nbr > 0 ? nbr : -nbr;
	len_nbr = digit_nb(tmp, len);
	if (nbr < 0)
		len_nbr++;
	res = malloc(sizeof(char) * (len_nbr + 1));
	if (res)
	{
		if (nbr < 0)
		{
			res[0] = '-';
			uitoa_base_(tmp, base, res + 1, len_nbr - 1);
		}
		else
			uitoa_base_(tmp, base, res, len_nbr);
		res[len] = 0;
	}
	return (res);
}
