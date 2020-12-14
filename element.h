/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caracteristics.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 11:02:48 by praclet           #+#    #+#             */
/*   Updated: 2020/12/14 14:25:44 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CARACTERISTICS_H
# define CARACTERISTICS_H

# include "ft_printf.h"

# define FLAG_SHARP		1
# define FLAG_ZERO		2
# define FLAG_DASH		4
# define FLAG_SPACE		8
# define FLAG_PLUS		16
# define FLAG_DOT		32
# define FLAG_STAR		64

# define MODIFIER_L		1
# define MODIFIER_LL	2
# define MODIFIER_H		4
# define MODIFIER_HH	8

typedef enum		e_conversion {
	none = '\0',
	c = 'c',
	s = 's',
	p = 'p',
	d = 'd',
	i = 'i',
	u = 'u',
	x = 'x',
	X = 'X',
	n = 'n',
	f = 'f',
	g = 'g',
	e = 'e',
	p100 = '%'
}					t_conversion;

typedef struct		s_caracteristics {
	int				flags;
	int				width;
	int				precision;
	int				modifiers;
	t_conversion	conversion;
}					t_caracteristics;

t_caracteristics	*new_caracteristics(void);
void				check_caracteristics(t_caracteristics *elem);

#endif
