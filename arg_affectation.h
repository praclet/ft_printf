/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_affectation.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <praclet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 12:50:37 by praclet           #+#    #+#             */
/*   Updated: 2020/12/23 13:02:45 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_AFFECTATION_H
# define ARG_AFFECTATION_H

# include <stdarg.h>
# include "list.h"

void	affectation(t_chain *list, va_list ap);

#endif
