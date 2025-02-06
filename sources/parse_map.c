/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:17:34 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/06 17:24:51 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	copy_map(t_game *game)
{
	int	y;

	y = 0;
	game->map_cpy = malloc((game->y + 1) * sizeof(char *));
	while(game->map[y])
	{
		game->map_cpy[y] = ft_strdup(game->map[y]);
		if (!game->map_cpy[y])
			ft_error_free(1, game);
		y++;
	}
}

static void player_position(t_game *game)
{
	int	x;
	int	y;
	
	x = 1;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				break ;
			}
			y++;
		}
		x++;
		if (game->player_x)
			break ;
	}
}

static void	flood_fill(t_game *game, int x, int y)
{
	game->map_cpy[x][y] = 'A';
	if (game->map_cpy[x][y - 1] != '1' && game->map_cpy[x][y - 1] != 'A')
		flood_fill(game, x, (y - 1));
	if (game->map_cpy[x + 1][y] != '1' && game->map_cpy[x + 1][y] != 'A')
		flood_fill(game, (x + 1), y);
	if (game->map_cpy[x][y + 1] != '1' && game->map_cpy[x][y + 1] != 'A')
		flood_fill(game, x, (y + 1));
	if (game->map_cpy[x - 1][y] != '1' && game->map_cpy[x - 1][y] != 'A')
		flood_fill(game, (x - 1), y);
}

static void	outside_flood_fill(t_game *game)
{
	int	p_x;
	int	p_y;
	int	i;
	
	i = 0;
	player_position(game);
	p_x = game->player_x;
	p_y = game->player_y;
	flood_fill(game, p_x, p_y);
	while(game->map_cpy[i])
	{
		if (ft_strchr(game->map_cpy[i], 'C')
			|| ft_strchr(game->map_cpy[i], 'E'))
			ft_error(10);
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
}

void	parse_map(t_game *game)
{
	int i;
	
	i = 0;
	while (game->map[0][i])
	{
		if (game->map[0][i] != '1')
			ft_error(8);
		i++;
	}
	i = 0;
	while (game->map[i])
	{
		if (game->map[i][0] != '1' || game->map[i][game->x - 1] != '1')
			ft_error(8);
		i++;
	}
	i = 0;
	while (game->map[game->y - 1][i])
	{
		if (game->map[game->y - 1][i] != '1')
			ft_error(8);
		i++;
	}
	copy_map(game);
	outside_flood_fill(game);
}
