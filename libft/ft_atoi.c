/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:43:40 by praclet           #+#    #+#             */
/*   Updated: 2020/11/24 04:08:25 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(char *str)
{
	int	sign;
	int	res;
	int	len;

	sign = 1;
	res = 0;
	len = 0;
	while (*str && (*str == ' ' || (*str >= '\t' && *str <= '\r')))
		str++;
	if (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
		len++;
		if (len > 18)
			return (sign < 0 ? 0 : -1);
	}
	return (sign * res);
}
