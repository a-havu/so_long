/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:17:34 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/03 16:32:32 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void player_position(t_game *game, int p_x, int p_y)
{
	int	x;
	int	y;
	
	y = 0;
	while (game->map)
	{
		x = 0;
		while (game->map[y])
		{
			if (game->map[y][x] == 'P')
			{
				p_y = y;
				p_x = x;
			}
			x++;
		}
		y++;
	}
}

static void	flood_fill(t_game *game, int x, int y)
{
	int	coll;
	
	coll = 0;
	game->map_cpy[x][y] = 'A';
	if ()
	
	// check each 4 directions adjacent to the player
	// if a tile is '1', it's unaccessible
	// mark every tile that's not '1' with an 'x'
	// keep count of the collectibles amount
	// at the end, check that the amount of collectibles is correct
}

static void	prep_to_flood_fill(t_game *game)
{
	int	p_x;
	int	p_y;
	
	player_position(game, &p_x, &p_y);
	flood_fill(game, p_x, p_y);
}

void	parse_map(t_game *game)
{
	int i;
	
	i = 0;
	while (game->map[0])
	{
		if (game->map[0][i] != '1')
			ft_error(8);
		i++;
	}
	i = 0;
	while (game->map)
	{
		if (game->map[i][0] != '1' || game->map[i][game->x - 1] != '1')
			ft_error(8);
		i++;
	}
	i = 0;
	while (game->map[game->y])
	{
		if (game->map[game->y][i] != '1')
			ft_error(8);
		i++;
	}
	game->map_cpy = game->map;
	prep_to_flood_fill(game);
}
