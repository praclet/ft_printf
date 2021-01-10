/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion2.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 13:31:43 by praclet           #+#    #+#             */
/*   Updated: 2021/01/10 17:56:37 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION2_H
# define CONVERSION2_H

# include "list.h"

int				convert_number_(t_chain *list);

typedef struct	s_carac
{
	int			sgn;
	int			zero_x;
	int			pos;
	int			width;
	int			prec;
	int			len;
	int			len_str;
	char		*base;
}				t_carac;

#endif
