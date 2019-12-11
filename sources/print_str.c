/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:31:32 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/23 16:02:44 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_str(char *str, int print, int count)
{
	static char		*tmp;
	static char		buf[512];
	static int		i;
	static size_t	j;

	buf[i] = '\0';
	while (str && count--)
	{
		if (i == 510)
		{
			tmp = ft_memrejoin(tmp, buf, &j, i);
			i = 0;
		}
		buf[i] = *str;
		++str;
		++i;
	}
	if (print)
	{
		tmp = ft_memrejoin(tmp, buf, &j, i);
		write(1, tmp, j);
		ft_strdel(&tmp);
		i = 0;
		j = 0;
	}
}
