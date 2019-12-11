/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrejoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwisoky <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:01:02 by dwisoky           #+#    #+#             */
/*   Updated: 2019/10/23 16:09:27 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrejoin(void *dst, void *src, size_t *len_dst, size_t len_src)
{
	void	*new;

	new = (void*)ft_memalloc(*len_dst + len_src);
	ft_memcpy(new, dst, *len_dst);
	ft_memcpy(new + *len_dst, src, len_src);
	free(dst);
	*len_dst += len_src;
	return (new);
}
