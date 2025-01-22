/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:21:21 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/09 16:36:40 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_plus.h"

static int	digit_counter(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		n = -n;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*zero(void)
{
	char	*str;

	str = ft_calloc(2, sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	ui;
	int				digit_count;

	if (n == 0)
		return (zero());
	digit_count = digit_counter(n);
	if (n < 0)
	{
		ui = n * -1;
		digit_count++;
	}
	else
		ui = n;
	str = ft_calloc(digit_count + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	while (ui)
	{
		str[--digit_count] = (ui % 10) + '0';
		ui /= 10;
	}
	return (str);
}
