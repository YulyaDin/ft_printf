/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:43:27 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/21 18:10:43 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_args(int nb, va_list args)
{
	static va_list	begin;

	if (nb == -2)
	{
		va_copy(begin, args);
		return ;
	}
	if (!nb)
		return ;
	va_copy(args, begin);
	nb -= 1;
	while (nb)
	{
		--nb;
		va_arg(args, void*);
	}
	return ;
}
