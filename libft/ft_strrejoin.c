/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrejoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:57:06 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/25 18:57:07 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrejoin(char *str, char *src, int is_free)
{
	char	*tmp;

	if (!str)
		return (ft_strdup(src));
	tmp = ft_strjoin(str, src);
	if (is_free & 1 && str)
		free(str);
	if (is_free & 2 && src)
		free(src);
	return (tmp);
}
