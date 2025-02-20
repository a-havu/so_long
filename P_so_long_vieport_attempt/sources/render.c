/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 08:27:47 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/20 08:53:27 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_viewport_vars(t_game *game)
{
	game->render_x = game->p_x - (WIDTH / TILE) / 2;
    game->render_y = game->p_y - (HEIGHT / TILE) / 2;
        if (game->render_x < 0)
			game->render_x = 0;
        if (game->render_y < 0)
			game->render_y = 0;
        if (game->render_x + (WIDTH / TILE) > game->x)
			game->render_x = game->x - (WIDTH / TILE);
        if (game->render_y + (HEIGHT / TILE) > game->y)
			game->render_y = game->y - (HEIGHT / TILE);
}

void	render_map(t_game *game, t_assets *assets)
{
	size_t	x;
	size_t	y;
	int		screen_x;
	int		screen_y;
	
	if (game->viewport_mode)
		update_viewport_vars(game);
	y = game->render_y;
	while (game->map[y] && y < game->render_y + HEIGHT / TILE + 1)
	{
		x = game->render_x;
		while (game->map[y][x] && x < game->render_x + WIDTH / TILE + 1)
		{
			screen_x = (x - game->render_x) * TILE;
			screen_y = (y - game->render_y) * TILE;
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx_ptr, assets->wall,
					screen_x, screen_y);
			if (game->map[y][x] != '1')
				mlx_image_to_window(game->mlx_ptr, assets->floor,
					screen_x, screen_y);
			x++;
		}
		y++;
	}
}

void	render_exits(t_game *game, t_assets *assets)
{
	size_t	x;
	size_t	y;
	int		screen_y;
	int		screen_x;
	
	if (game->viewport_mode)
		update_viewport_vars(game);
	y = game->render_y;
	while(game->map[y] && y < game->render_y + HEIGHT / TILE)
	{
		x = game->render_x;
		while (game->map[y][x] && x < game->render_x + WIDTH / TILE)
		{
			screen_x = (x - game->render_x) * TILE;
			screen_y = (y - game->render_y) * TILE;
			if (game->map[y][x] == 'E')
			{
				mlx_image_to_window(game->mlx_ptr, assets->exit_closed,
					screen_x, screen_y);
				mlx_image_to_window(game->mlx_ptr, assets->exit_open,
					screen_x, screen_y);
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
	size_t	x;
	size_t	y;
	int		p;
	int		screen_y;
	int		screen_x;

	if (game->viewport_mode)
		update_viewport_vars(game);
	y = game->render_y;
	p = 0;
	while (game->map[y] && y < game->render_y + HEIGHT / TILE)
	{
		x = game->render_x;
		while (game->map[y][x] && x < game->render_x + WIDTH / TILE)
		{
			screen_x = (x - game->render_x) * TILE;
			screen_y = (y - game->render_y) * TILE;
			if (game->map[y][x] == 'C')
			{
				mlx_image_to_window(game->mlx_ptr, assets->coll,
					screen_x, screen_y);
				mlx_image_to_window(game->mlx_ptr, assets->puddle,
					screen_x, screen_y);
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
	size_t	x;
	size_t	y;
	int		screen_y;
	int		screen_x;

	if (game->viewport_mode)
		update_viewport_vars(game);
	y = game->render_y;
	while(game->map[y] && y < game->render_y + HEIGHT / TILE)
	{
		x = game->render_x;
		while (game->map[y][x] && x < game->render_x + WIDTH / TILE)
		{
			screen_x = (x - game->render_x) * TILE;
			screen_y = (y - game->render_y) * TILE;
			if (game->map[y][x] == 'P')
				mlx_image_to_window(game->mlx_ptr, assets->player,
					screen_x, screen_y);
			x++;
		}
		y++;
	}
}
