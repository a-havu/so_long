/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_longlong.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:16:19 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/09 16:42:03 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_plus.h"

static long long	loop(long long res, int neg, const char *nptr, int i)
{
	long long	prev_result;

	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		prev_result = res;
		res = res * 10 + (nptr[i] - '0');
		if (prev_result > res && neg == 1)
			return (-1);
		if (prev_result > (res + 1) && neg == -1)
			return (0);
		i++;
	}
	return (res * neg);
}

long long	ft_atoi_longlong(const char *nptr)
{
	int		    i;
	long long	res;
	int		    neg;

	i = 0;
	res = 0;
	neg = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
	{
		neg = -neg;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	return (loop(res, neg, nptr, i));
}