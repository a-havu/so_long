/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:30:59 by ahavu             #+#    #+#             */
/*   Updated: 2024/12/04 11:33:23 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	cases_check(uintptr_t unb, char c)
{
	if (c == 'x')
	{
		if (print_char((unb % 16) - 10 + 'a') < 0)
			return (-1);
	}
	else if (c == 'X')
	{
		if (print_char((unb % 16) - 10 + 'A') < 0)
			return (-1);
	}
	return (1);
}

int	print_hex(uintptr_t unb, char c)
{
	int	len;
	int	tmp;

	len = 0;
	if (unb == 0)
		return (print_char('0'));
	if (unb >= 16)
	{
		tmp = print_hex(unb / 16, c);
		if (tmp < 0)
			return (-1);
		len += tmp;
	}
	if (unb % 16 <= 9)
	{
		if (print_char(unb % 16 + '0') < 0)
			return (-1);
	}
	else
	{
		if (cases_check(unb, c) < 0)
			return (-1);
	}
	len++;
	return (len);
}
