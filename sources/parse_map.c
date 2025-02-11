/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:17:34 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/11 10:02:02 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	copy_map(t_game *game)
{
	int	y;

	y = 0;
	game->map_cpy = ft_calloc((game->y + 1), sizeof(char *));
	while (game->map[y])
	{
		game->map_cpy[y] = ft_strdup(game->map[y]);
		if (!game->map_cpy[y])
			ft_error(2, game);
		y++;
	}
}

static void	player_position(t_game *game)
{
	int	y;
	int	x;

	y = 1;
	while (game->map[y])
	{
		x = 1;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->p_x = x;
				game->p_y = y;
				break ;
			}
			x++;
		}
		y++;
		if (game->p_x)
			break ;
	}
}

static void	flood_fill(t_game *game, int y, int x)
{
	game->map_cpy[y][x] = 'A';
	if (game->map_cpy[y][x - 1] != '1' && game->map_cpy[y][x - 1] != 'A')
		flood_fill(game, y, (x - 1));
	if (game->map_cpy[y + 1][x] != '1' && game->map_cpy[y + 1][x] != 'A')
		flood_fill(game, (y + 1), x);
	if (game->map_cpy[y][x + 1] != '1' && game->map_cpy[y][x + 1] != 'A')
		flood_fill(game, y, (x + 1));
	if (game->map_cpy[y - 1][x] != '1' && game->map_cpy[y - 1][x] != 'A')
		flood_fill(game, (y - 1), x);
}

static void	outside_flood_fill(t_game *game)
{
	int	p_x;
	int	p_y;
	int	i;

	i = 0;
	player_position(game);
	p_x = game->p_x;
	p_y = game->p_y;
	flood_fill(game, p_y, p_x);
	while (game->map_cpy[i])
	{
		if (ft_strchr(game->map_cpy[i], 'C')
			|| ft_strchr(game->map_cpy[i], 'E'))
			ft_error(10, game);
		i++;
	}
	i = 0;
	while (game->map_cpy[i])
	{
		free(game->map_cpy[i]);
		game->map_cpy[i] = NULL;
		i++;
	}
	free (game->map_cpy);
	game->map_cpy = NULL;
}

void	parse_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1')
			ft_error(8, game);
		i++;
	}
	i = 0;
	while (game->map[i])
	{
		if (game->map[i][0] != '1' || game->map[i][game->x - 1] != '1')
			ft_error(8, game);
		i++;
	}
	i = 0;
	while (game->map[game->y - 1][i])
	{
		if (game->map[game->y - 1][i] != '1')
			ft_error(8, game);
		i++;
	}
	copy_map(game);
	outside_flood_fill(game);
}
