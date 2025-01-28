/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:39:33 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/09 16:37:40 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_plus.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*temp_dest;
	unsigned char	*temp_src;

	i = -1;
	if (!n)
		return (dest);
	temp_dest = (unsigned char *)dest;
	temp_src = (unsigned char *)src;
	if (temp_src < temp_dest)
	{
		while (n > 0)
		{
			temp_dest[n - 1] = temp_src[n - 1];
			n--;
		}
	}
	if (temp_src > temp_dest)
	{
		while (++i < n)
			temp_dest[i] = temp_src[i];
	}
	return (dest);
}
