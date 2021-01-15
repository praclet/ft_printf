/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 00:18:31 by praclet           #+#    #+#             */
/*   Updated: 2020/11/25 00:18:34 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new_lst)
{
	if (alst)
	{
		if (*alst)
			ft_lstlast(*alst)->next = new_lst;
		else
			*alst = new_lst;
	}
}
