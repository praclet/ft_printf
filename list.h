/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 11:02:48 by praclet           #+#    #+#             */
/*   Updated: 2020/12/23 10:35:06 by praclet          ###   ########lyon.fr   */
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
# define FLAG_DOT		32
# define FLAG_STAR		64

# define MODIFIER_L		1
# define MODIFIER_LL	2
# define MODIFIER_H		4
# define MODIFIER_HH	8

# define CONVERSION		"cspdiuxXnfge%"

typedef struct					s_chain {
	char						*str;
	union
	{
		char					arg_char;
		char					*arg_pchar;
		wchar_t					*arg_wchar_t;
		signed char				arg_schar;
		unsigned char			arg_uchar;
		double					arg_double;
		void					*arg_ptr;
		int						arg_int;
		unsigned int			arg_uint;
		long int				arg_lint;
		short int				arg_short_int;
		unsigned short int		arg_u_short_int;
		unsigned long int		arg_ulint;
		long long int			arg_llint;
		unsigned long long int	arg_ullint;
		wint_t					arg_wint_t;
	}							u_arg;
	unsigned char				flags;
	int							width;
	int							precision;
	unsigned char				modifiers;
	char						conversion;
	struct s_chain				*next;
}								t_chain;

t_chain							*new_elem(void);
t_chain							*check_list(t_chain *list);
void							delete_elem(t_chain *elem);
void							delete_list(t_chain *list);
char							*list_finish(t_chain *list);

#endif
