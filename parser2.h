/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 11:24:12 by praclet           #+#    #+#             */
/*   Updated: 2021/01/11 12:28:46 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER2_H
# define PARSER2_H

# include "list.h"

int		parse_text(const char **str, t_chain **res, t_chain **cur,
		t_chain **last);
t_chain	*add_element(t_chain **res, t_chain **last);
t_chain	*parse_(char *str);

#endif
