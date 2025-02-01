/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:37:58 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/01 17:20:00 by ahavu            ###   ########.fr       */
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

static void	validate_symbols(t_game *game)
{
	if (game->exit > 1)
		ft_error(3);
	else if (game->player > 1)
		ft_error(4);
	else if (game->exit == 0)
		ft_error(5);
	else if (game->player == 0)
		ft_error(6);
	else if (game->coll < 1)
		ft_error(7);
}

static void	check_symbols(t_game *game)
{
	int i;
	int	k;

	i = 0;
	while (game->map[i])
	{
		k = 0;
		while(game->map[i][k])
		{
			if (game->map[i][k] == 'E')
				game->exit += 1;
			else if (game->map[i][k] == 'P')
				game->player += 1;
			else if (game->map[i][k] == 'C')
				game->coll += 1;
			else if (game->map[i][k] != '0' && game->map[i][k] != '1')
				ft_error(8);
			k++;
		}
		i++;
	}
	validate_symbols(game);
}

void	initialize_map(char *arg, t_game *game)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		ft_error(8);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			ft_error_free(1, game);
		if (i == 0)
			game->x = ft_strlen(line);
		if (game->x != ft_strlen(line))
			ft_error(8);
		game->map[i] = line;
		i++;
	}
	game->y = i;
	check_symbols(game);
	close(fd);
}
