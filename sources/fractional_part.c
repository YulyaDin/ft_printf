/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractional_part.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:15:33 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/25 19:15:34 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "double.h"

static int	sum_lst(t_number *lst1, t_number *lst2)
{
	int tmp;

	tmp = 0;
	if (!lst2->next)
	{
		tmp = lst1->num + lst2->num;
		lst1->num = tmp % 10;
		return (tmp / 10);
	}
	else
	{
		tmp = lst1->num + lst2->num + sum_lst(lst1->next, lst2->next);
		lst1->num = tmp % 10;
		return (tmp / 10);
	}
	return (0);
}

t_number	*get_fractional_part(int exp, char *frac)
{
	t_number	*lst;
	t_number	*tmp;

	lst = new_num(0);
	while (exp >= 0)
	{
		--exp;
		++frac;
	}
	while (*frac)
	{
		if (*frac == '1')
		{
			tmp = ft_big_pow(exp);
			sum_lst(tmp, lst);
			free_num(&lst);
			lst = tmp;
		}
		--exp;
		++frac;
	}
	return (lst);
}
