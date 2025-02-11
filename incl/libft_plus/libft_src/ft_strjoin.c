/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:16:06 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/09 16:38:40 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_plus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	total_len;
	int		i;
	int		k;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	k = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2);
	new_str = ft_calloc((total_len + 1), sizeof(char));
	if (!new_str)
		return (NULL);
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[k])
		new_str[i++] = s2[k++];
	new_str[i] = '\0';
	return (new_str);
}
