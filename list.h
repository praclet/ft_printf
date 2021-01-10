/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 11:02:48 by praclet           #+#    #+#             */
/*   Updated: 2021/01/10 15:06:36 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include <wchar.h>

# define FLAG_SHARP		1
# define FLAG_ZERO		2
# define FLAG_DASH		4
# define FLAG_SPACE		8
# define FLAG_PLUS		16
# define FLAG_NEG		32

# define MODIFIER_L		1
# define MODIFIER_LL	2
# define MODIFIER_H		4
# define MODIFIER_HH	8

typedef struct					s_chain {
	char						*str;
	union
	{
		unsigned long long int	arg_ullint;
		double					arg_double;
		int						arg_int;
		wint_t					arg_wint_t;
		void					*arg_ptr;
	}							u_arg;
	unsigned char				flags;
	int							width;
	int							precision;
	unsigned char				modifiers;
	char						conversion;
	struct s_chain				*next;
}								t_chain;

t_chain							*new_elem(void);
void							check_list(t_chain *list);
void							delete_elem(t_chain *elem);
void							delete_list(t_chain *list);
char							*list_finish(t_chain *list, int length);

#endif
