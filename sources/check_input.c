/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:37:58 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/31 16:41:57 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_filetype(char *arg)
{
	if (ft_strlen(arg) >= 5)
	{
		arg = arg + ft_strlen(arg) - 4;
		if (ft_strncmp(arg, ".ber", 4))
			return (0);
		return (1);
	}
	return (0);
}

static void	check_symbols(char *line, t_game *game)
{
	if (ft_strchr(line, 'E'))
	{
		game->e += 1;
		if (game->e > 1)
			ft_error(3);
	}
	else if (ft_strchr(line, 'P'))
	{
		game->p += 1;
		if (game->p > 1)
			ft_error(4);
	}
	else if (ft_strchr(line, 'C'))
		game->c += 1;
	
}

int	initialize_map(char *arg, t_game *game)
{
	char	*line;
	int		fd;
	int		len;
	int		second_len;

	fd = open(arg, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		len = ft_strlen(line);
		check_symbols(line, game);
	}
	if (game->e == 0)
		ft_error(5);
	if (game->p == 0)
		ft_error(6);
	if (game->c < 1)
		ft_error(7);
	close(fd);
}
