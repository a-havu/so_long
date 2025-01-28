/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:50:46 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/09 16:37:59 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_plus.h"

static int	word_count(char const *s, char c)
{
	int	i;
	int	w;

	w = 0;
	i = 0;
	if (!*s)
		return (0);
	if (s[0] != c)
		w++;
	while (s[i])
	{
		if ((s[i] == c) && (s[i + 1] != c))
			w++;
		i++;
	}
	if (*s && s[ft_strlen(s) - 1] == c)
		w--;
	return (w);
}

static void	free_everything(char **str_array)
{
	int	i;

	i = 0;
	while (str_array[i])
	{
		free(str_array[i]);
		str_array[i] = NULL;
		i++;
	}
	free(str_array);
}

static char	*fill_word(char const *s, int start, int end, char **str_array)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_calloc((end - start + 1), sizeof(char));
	if (!tmp)
	{
		free_everything(str_array);
		return (NULL);
	}
	while (start < end)
	{
		tmp[i] = s[start];
		start++;
		i++;
	}
	return (tmp);
}

char	**ft_split(char const *s, char c)
{
	char	**str_array;
	size_t	i;
	int		x;
	int		trig;

	i = 0;
	x = 0;
	trig = -1;
	if (!s)
		return (NULL);
	str_array = ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (!str_array)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && trig < 0)
			trig = i;
		else if ((s[i] == '\0' || s[i] == c) && trig >= 0)
		{
			str_array[x++] = fill_word(s, trig, i, str_array);
			trig = -1;
		}
		i++;
	}
	return (str_array);
}
