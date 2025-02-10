/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:44:04 by ahavu             #+#    #+#             */
/*   Updated: 2024/11/29 13:56:18 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_uint(unsigned int n)
{
	char	c;
	int		i;
	int		tmp;

	i = 0;
	if (n >= 10)
	{
		tmp = print_uint(n / 10);
		if (tmp < 0)
			return (-1);
		i += tmp;
	}
	c = (n % 10) + 48;
	if (print_char(c) < 0)
		return (-1);
	i++;
	return (i);
}
