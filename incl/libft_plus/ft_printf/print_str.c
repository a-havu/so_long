/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:47:48 by ahavu             #+#    #+#             */
/*   Updated: 2024/12/04 09:40:23 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_str(char *s)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	if (!s)
	{
		tmp = print_str("(null)");
		if (tmp < 0)
			return (-1);
		return (tmp);
	}
	while (s[i])
	{
		if (print_char(s[i]) < 0)
			return (-1);
		i++;
	}
	return (i);
}
