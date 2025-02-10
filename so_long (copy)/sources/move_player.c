/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:26:02 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/10 14:33:21 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	collect(t_game *game, t_assets *assets)
{
	game->map[game->p_y][game->p_x] = 'X';
	mlx_image_to_window(game->mlx_ptr, assets->puddle,
		game->p_x * TILE, game->p_y * TILE);
	game->collected++;
	if (game->collected == game->coll)
		mlx_image_to_window(game->mlx_ptr, assets->exit_open,
			game->exit_x * TILE, game->exit_y * TILE);
}

static void	validate_movement_y(t_game *game, int dir, t_assets *assets)
{
	if (game->map[game->p_y + dir][game->p_x] != '1')
	{
		if (game->map[game->p_y + dir][game->p_x] == 'E'
		&& game->collected == game->coll)
			ft_exit(game, 1);
		else
		{
			mlx_image_to_window(game->mlx_ptr, assets->floor,
				game->p_x * TILE, game->p_y * TILE);
			if (game->map[game->p_y][game->p_x] == 'C')
				collect(game, assets);
			game->p_y += dir;
		}
	}
}

static void	validate_movement_x(t_game *game, int dir, t_assets *assets)
{
	if (game->map[game->p_y][game->p_x + dir] != '1')
	{
		if (game->map[game->p_y][game->p_x + dir] == 'E'
		&& game->collected == game->coll)
			ft_exit(game, 1);
		else
		{
			mlx_image_to_window(game->mlx_ptr, assets->floor,
				game->p_x * TILE, game->p_y * TILE);
			if (game->map[game->p_y][game->p_x] == 'C')
				collect(game, assets);
			game->p_x += dir;
		}
	}
}

void	move_player(t_game *game, t_assets *assets, char ax, int dir)
{
	if (ax == 'y')
		validate_movement_y(game, dir, assets);
	else if (ax == 'x')
		validate_movement_x(game, dir, assets);
	mlx_image_to_window(game->mlx_ptr, assets->player,
			game->p_x * TILE, game->p_y * TILE);
	ft_printf("BAT! You've flown %d times\n", game->moves++);
}
