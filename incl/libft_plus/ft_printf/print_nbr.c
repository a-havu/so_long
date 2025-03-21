/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:33:43 by ahavu             #+#    #+#             */
/*   Updated: 2024/11/29 14:39:22 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	handle_edgecase(int n)
{
	int	res;

	res = 0;
	if (n == -2147483648)
		res = print_str("-2147483648");
	else if (n == 0)
		res = print_char('0');
	if (res < 0)
		return (-1);
	return (res);
}

static int	conversion(int n, int i)
{
	char	c;
	int		ret;

	if (n >= 10)
	{
		ret = print_nbr(n / 10);
		if (ret < 0)
			return (-1);
		i += ret;
	}
	c = (n % 10) + 48;
	if (print_char(c) < 0)
		return (-1);
	i++;
	return (i);
}

int	print_nbr(int n)
{
	int		i;

	i = 0;
	if (n == -2147483648 || n == 0)
		return (handle_edgecase(n));
	if (n < 0)
	{
		n = -n;
		if (print_char('-') < 0)
			return (-1);
		i++;
	}
	return (conversion(n, i));
}
