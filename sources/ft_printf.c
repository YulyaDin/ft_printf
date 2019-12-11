/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abartole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:08:39 by abartole          #+#    #+#             */
/*   Updated: 2019/10/25 19:26:27 by dwisoky          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_dollar(char **str, t_printf *flags)
{
	int	i;
	int	nb;

	i = 1;
	nb = 0;
	if ((*str)[i] == '0')
		return (check_dollar_norm(str));
	while ((*str)[i] >= '0' && (*str)[i] <= '9')
	{
		nb = nb * 10 + ((*str)[i] - '0');
		++i;
	}
	if ((*str)[i] == '$')
	{
		flags->dollar = nb;
		if (i == 1)
			return (0);
		(*str) += i;
	}
	return (1);
}

void	initialize_flags(t_printf *flags)
{
	flags->plus = 0;
	flags->minus = 0;
	flags->hash = 0;
	flags->zero = 0;
	flags->space = 0;
	flags->precision = -1;
	flags->width = -1;
	flags->size = 0;
	flags->conversion = 0;
	flags->h = 0;
	flags->hh = 0;
	flags->l = 0;
	flags->ll = 0;
	flags->lld = 0;
	flags->z = 0;
	flags->j = 0;
	flags->dollar = 0;
}

int		print_format(char **format, va_list args, t_printf *flags)
{
	char	*str;

	if (!(str = check_format(format, args, flags)))
		return (0);
	flags->size += ft_strlen(str);
	print_str(str, 0, flags->size);
	if (str)
		free(str);
	flags->total += flags->size;
	return (1);
}

int		read_format(char **format, va_list args)
{
	t_printf	flags;
	char		*tmp;

	flags.total = 0;
	while (**format)
	{
		tmp = *format;
		initialize_flags(&flags);
		if (**format == '%')
		{
			if (check_dollar(format, &flags))
				if (!(print_format(format, args, &flags)))
					return (flags.total);
		}
		else
		{
			print_str(*format, 0, 1);
			flags.total++;
		}
		(*format)++;
	}
	return (flags.total);
}

int		ft_printf(const char *format, ...)
{
	va_list args;
	int		printed;

	if (!format || !*format)
		return (0);
	va_start(args, format);
	get_args(-2, args);
	printed = read_format((char **)&format, args);
	va_end(args);
	print_str(NULL, 1, 0);
	return (printed);
}
