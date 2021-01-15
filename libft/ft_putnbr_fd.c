/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 00:16:04 by praclet           #+#    #+#             */
/*   Updated: 2020/11/25 00:16:06 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	ft_putnbr_fd_(long nb, int fd)
{
	char	tmp;

	if (nb < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd_(-nb, fd);
	}
	else
	{
		if (nb < 10)
		{
			tmp = '0' + nb;
			write(fd, &tmp, 1);
		}
		else
		{
			ft_putnbr_fd_(nb / 10, fd);
			ft_putnbr_fd_(nb % 10, fd);
		}
	}
}

void		ft_putnbr_fd(int nb, int fd)
{
	ft_putnbr_fd_(nb, fd);
}
