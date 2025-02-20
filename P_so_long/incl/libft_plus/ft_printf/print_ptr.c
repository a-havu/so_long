/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:47:00 by ahavu             #+#    #+#             */
/*   Updated: 2024/11/29 14:39:42 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_ptr(uintptr_t ptr)
{
	int	len;
	int	tmp;

	if (!ptr)
		return (print_str("(nil)"));
	if (print_str("0x") < 0)
		return (-1);
	len = 2;
	tmp = print_hex(ptr, 'x');
	if (tmp < 0)
		return (-1);
	len += tmp;
	return (len);
}
