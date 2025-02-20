/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:01:33 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/09 16:37:31 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_plus.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	uc_c;
	unsigned char	*uc_s;

	i = 0;
	uc_c = (unsigned char)c;
	uc_s = (unsigned char *)s;
	while (i < n)
	{
		if (uc_s[i] == uc_c)
			return ((void *)uc_s + i);
		i++;
	}
	return (NULL);
}
