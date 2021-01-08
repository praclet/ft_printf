/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: praclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 14:19:01 by praclet           #+#    #+#             */
/*   Updated: 2021/01/06 16:21:10 by praclet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITOA_BASE_H
# define ITOA_BASE_H

void	itoa_base(long long int nbr, char *base, char *res);
void	uitoa_base(long long unsigned int nbr, char *base, char *res);
int		digit_nb(long long int nb, int len);
int		digit_unb(long long unsigned int nb, int len);

#endif
