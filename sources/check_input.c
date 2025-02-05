/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:37:58 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/05 16:30:17 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_input(int argc, char *arg)
{
	if (argc > 2)
	{
		ft_error(2);
		exit(EXIT_FAILURE);
	}
	if (ft_strlen(arg) >= 5)
	{
		arg = arg + ft_strlen(arg) - 4;
		if (ft_strncmp(arg, ".ber", 4))
		{
			ft_error(0);
			exit(EXIT_FAILURE);
		}
	}
	else if (ft_strlen(arg) < 5)
	{
		ft_error(0);
		exit(EXIT_FAILURE);
	}
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
				ft_error(9);
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

	line = NULL;
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		ft_error(8);
	game->map = malloc(5 * sizeof(char *));
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
	check_symbols(game);
	close(fd);
}
