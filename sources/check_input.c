/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:37:58 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/06 13:03:43 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_input(int argc, char *arg)
{
	if (argc > 2)
		ft_error(2);
	if (argc < 2)
		ft_error(0);
	if (ft_strlen(arg) >= 5)
	{
		arg = arg + ft_strlen(arg) - 4;
		if (ft_strncmp(arg, ".ber", 4))
			ft_error(0);
	}
	else if (ft_strlen(arg) < 5)
		ft_error(0);
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

void	check_symbols(t_game *game)
{
	int i;
	int	k;

	i = 0;
	if (!game->map[i])
		ft_error(11);
	while (game->map[i])
	{
		k = 0;
		while(game->map[i][k])
		{
			if (game->map[i][k] == 'E')
				game->exit++;
			else if (game->map[i][k] == 'P')
				game->player++;
			else if (game->map[i][k] == 'C')
				game->coll++;
			else if (game->map[i][k] != '0' && game->map[i][k] != '1')
				ft_error(9);
			k++;
		}
		i++;
	}
	validate_symbols(game);
}

void	check_map(char *arg, t_game *game)
{
	char	*line;
	int		fd;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		ft_error(8);
	game->map = malloc(50 * sizeof(char *));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strchr(line, '\n'))
			*ft_strchr(line, '\n') = '\0';
		if (game->y == 0)
			game->x = ft_strlen(line);
		if (game->x != ft_strlen(line))
			ft_error(8);
		game->map[game->y] = ft_calloc((ft_strlen(line) + 1), sizeof(char));
		game->map[game->y] = line;
		game->y++;
	}
	game->map[game->y] = NULL;
	close(fd);
}
