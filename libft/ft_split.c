/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 00:16:29 by praclet           #+#    #+#             */
/*   Updated: 2020/11/25 00:16:31 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char			*ft_strndup(const char *src, unsigned int n)
{
	char	*dest;
	char	*dest_tmp;

	dest = (char *)ft_calloc(n + 1, sizeof(char));
	dest_tmp = dest;
	if (dest)
	{
		while (*src && n)
		{
			*dest++ = *src++;
			n--;
		}
		*dest = 0;
	}
	return (dest_tmp);
}

static const char	*ft_next_stop(const char *cur, char c)
{
	while (*cur)
	{
		if (c == *cur)
			return (cur);
		cur++;
	}
	return (cur);
}

static int			ft_size(const char *str, char c)
{
	const char	*ahead;
	int			size;

	size = 0;
	while (*str)
	{
		ahead = ft_next_stop(str, c);
		if (str != ahead)
		{
			size++;
			str = *ahead ? ahead + 1 : ahead;
		}
		else
			str++;
	}
	return (size);
}

static char			**free_all(char **tab, int end)
{
	while (end)
	{
		free(tab[end - 1]);
		end--;
	}
	free(tab);
	return (NULL);
}

char				**ft_split(char const *str, char c)
{
	const char	*ahead;
	int			i;
	char		**tab;

	if (!str)
		return (NULL);
	tab = (char **)ft_calloc(ft_size(str, c) + 1, sizeof(char *));
	if (!tab)
		return (free_all(tab, 0));
	i = 0;
	while (*str)
	{
		ahead = ft_next_stop(str, c);
		if (str != ahead)
		{
			tab[i] = ft_strndup(str, ahead - str);
			if (!tab[i])
				return (free_all(tab, i - 1));
			str = *ahead ? ahead + 1 : ahead;
			i++;
		}
		else
			str++;
	}
	return (tab);
}
