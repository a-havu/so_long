/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:49:17 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/09 16:39:29 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_plus.h"

static int	char_in_set(char chr, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == chr)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*new_str;
	int			start;
	size_t		i;
	int			end;

	start = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	while (char_in_set(s1[start], set))
		start++;
	while (char_in_set(s1[end - 1], set) && end > start)
		end--;
	new_str = ft_calloc((end - start + 1), sizeof(char));
	if (!new_str)
		return (NULL);
	while (start < end)
		new_str[i++] = s1[start++];
	new_str[i] = '\0';
	return (new_str);
}
