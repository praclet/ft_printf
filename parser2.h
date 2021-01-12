/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 11:24:12 by praclet           #+#    #+#             */
/*   Updated: 2021/01/11 12:42:45 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER2_H
# define PARSER2_H

# include "list.h"

void	parse_flag(const char **str, t_chain *cur);
void	parse_prec(const char **str, t_chain *cur);
void	parse_width_prec(const char **str, t_chain *cur);
void	parse_modifier_conversion(const char **str, t_chain *cur);

#endif
