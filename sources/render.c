/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 08:27:47 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/11 08:49:40 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *game, t_assets *assets)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx_ptr, assets->wall,
					x * TILE, y * TILE);
			if (game->map[y][x] != '1')
				mlx_image_to_window(game->mlx_ptr, assets->floor,
					x * TILE, y * TILE);
			x++;
		}
		y++;
	}
}

void	render_exits(t_game *game, t_assets *assets)
{
	int	x;
	int	y;

	y = 1;
	while(game->map[y])
	{
		x = 1;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'E')
			{
				mlx_image_to_window(game->mlx_ptr, assets->exit_closed,
					x * TILE, y * TILE);
				mlx_image_to_window(game->mlx_ptr, assets->exit_open,
					x * TILE, y * TILE);
				game->exit_x = x;
				game->exit_y = y;
			}
			x++;
		}
		y++;
	}
	assets->exit_open->instances->enabled = false;
}

void	render_collectibles(t_game *game, t_assets *assets)
{
	int	x;
	int	y;
	int	p;

	y = 1;
	p = 0;
	while (game->map[y])
	{
		x = 1;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
			{
				mlx_image_to_window(game->mlx_ptr, assets->coll,
					x * TILE, y * TILE);
				mlx_image_to_window(game->mlx_ptr, assets->puddle,
					x * TILE, y * TILE);
				assets->puddle->instances[p].enabled = false;
				p++;
			}
			x++;
		}
		y++;
	}
}

void	render_player(t_game *game, t_assets *assets)
{
	int	x;
	int y;

	y = 1;
	while(game->map[y])
	{
		x = 1;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
				mlx_image_to_window(game->mlx_ptr, assets->player,
					x * TILE, y * TILE);
			x++;
		}
		y++;
	}
}
