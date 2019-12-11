/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:00:40 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/25 19:25:51 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			look_for_next(t_number *number, t_number *gg)
{
	if (number && number->num == 5)
	{
		number = number->next;
		if (!number)
			return (gg->num % 2);
		return (1);
	}
	if (!number || number->num < 5)
		return (0);
	return (1);
}

int			check_dollar_norm(char **str)
{
	int		i;

	i = 1;
	while ((*str)[i] == '0')
		++i;
	if ((*str)[i] == '$')
	{
		*str += i - 1;
		return (0);
	}
	return (1);
}
