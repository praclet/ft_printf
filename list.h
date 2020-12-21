/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 11:02:48 by praclet           #+#    #+#             */
/*   Updated: 2020/12/21 10:35:03 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

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

# define CONVERSION		"cspdiuxXnfge%"

typedef struct		s_chain {
	char			*str;
	void			*arg1;
	void			*arg2;
	unsigned char	flags;
	int				width;
	int				precision;
	unsigned char	modifiers;
	char			conversion;
	struct s_chain	*next;
}					t_chain;

t_chain				*new_elem(void);
t_chain				*check_list(t_chain *list);
void				delete_elem(t_chain *elem);
void				delete_list(t_chain *list);
char				*list_finish(t_chain *list);

#endif
