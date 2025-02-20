/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:03:44 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/09 16:37:34 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_plus.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*new_s1;
	unsigned char	*new_s2;

	i = 0;
	new_s1 = (unsigned char *)s1;
	new_s2 = (unsigned char *)s2;
	while (i < n)
	{
		if ((new_s1[i] - new_s2[i]) != 0)
			return (new_s1[i] - new_s2[i]);
		i++;
	}
	return (0);
}
