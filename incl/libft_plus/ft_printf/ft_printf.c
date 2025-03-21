/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:19:32 by ahavu             #+#    #+#             */
/*   Updated: 2024/12/05 10:00:24 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	print_arg(va_list args, char x)
{
	if (x == 'c')
		return (print_char(va_arg(args, int)));
	if (x == 's')
		return (print_str(va_arg(args, char *)));
	if (x == 'p')
		return (print_ptr(va_arg(args, uintptr_t)));
	if (x == 'd' || x == 'i')
		return (print_nbr(va_arg(args, int)));
	if (x == 'u')
		return (print_uint(va_arg(args, unsigned int)));
	if (x == 'x' || x == 'X')
		return (print_hex((va_arg(args, unsigned int)), x));
	if (x == '%')
		return (print_char('%'));
	return (0);
}

static int	print_loop(const char *initial_str, va_list args)
{
	int	i;
	int	len;
	int	tmp;

	i = 0;
	len = 0;
	while (initial_str[i])
	{
		if (initial_str[i] == '%' && (initial_str[i + 1]
				&& ft_strchr("cspdiuxX%", initial_str[i + 1])))
		{
			tmp = print_arg(args, initial_str[++i]);
			if (tmp < 0)
				return (-1);
			len += tmp;
			i++;
		}
		else
		{
			if (print_char(initial_str[i++]) < 0)
				return (-1);
			len++;
		}
	}
	return (len);
}

int	ft_printf(const char *initial_str, ...)
{
	int		ret;
	va_list	args;

	if (!initial_str)
		return (-1);
	va_start (args, initial_str);
	ret = print_loop(initial_str, args);
	va_end(args);
	return (ret);
}
