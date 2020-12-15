/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 11:02:48 by praclet           #+#    #+#             */
/*   Updated: 2020/12/15 09:20:01 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

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

typedef struct		s_list {
	char			*str;
	void			*arg1;
	void			*arg2;
	char			flags;
	int				width;
	int				precision;
	char			modifiers;
	t_conversion	conversion;
	struct s_list	*next;
}					t_list;

t_list				*new_list(void);
void				check_list(t_list *list);
void				delete_list(t_list *list);
char				*list_finish(t_list *list);

#endif
