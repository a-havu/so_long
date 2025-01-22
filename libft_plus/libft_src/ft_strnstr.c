/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:01:15 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/09 16:39:23 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_plus.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	l_i;
	size_t	li_len;

	i = 0;
	li_len = ft_strlen(little);
	if (li_len == 0)
		return ((char *)big);
	while (i < len && big[i])
	{
		l_i = 0;
		while (((i + l_i) < len && big[i + l_i]) && (little[l_i]) \
		&& (big[i + l_i] == little[l_i]))
		{
			l_i++;
			if (l_i == li_len)
				return ((char *)big + ((i + l_i) - li_len));
		}
		i++;
	}
	return (NULL);
}
