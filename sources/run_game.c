/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:32:50 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/06 17:49:26 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	render_map(t_game *game, t_assets *assets)
{
	int	x;
	int y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx_ptr, assets->wall,
					x * TILE_SIZE, y * TILE_SIZE);
			else if (game->map[y][x] != '1')
				mlx_image_to_window(game->mlx_ptr, assets->floor, 
					x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
	mlx_set_instance_depth()
	mlx_
}

static void load_images(t_assets *assets, t_game *game)
{
	assets->wall_t = mlx_load_png(WALL);
	assets->floor_t = mlx_load_png(FLOOR);
	assets->coll_t = mlx_load_png(COLL);
	assets->player_t = mlx_load_png(PLAYER);
	assets->exit_closed_t = mlx_load_png(EXIT_CLOSED);
	assets->exit_open_t = mlx_load_png(EXIT_OPEN);
	assets->wall = mlx_texture_to_image(game->mlx_ptr, assets->wall_t);
	assets->floor = mlx_texture_to_image(game->mlx_ptr, assets->floor_t);
	assets->coll = mlx_texture_to_image(game->mlx_ptr, assets->coll_t);
	assets->player = mlx_texture_to_image(game->mlx_ptr, assets->player_t);
	assets->exit_closed = mlx_texture_to_image(game->mlx_ptr,
							assets->exit_closed_t);
	assets->exit_open = mlx_texture_to_image(game->mlx_ptr,
							assets->exit_open_t);
}

void	run_game(t_game *game)
{
	t_assets	*assets;

	assets = malloc(sizeof(t_assets));
	game->mlx_ptr = mlx_init(WIDTH, HEIGHT, "FEED THE VAMP", true);
	if (!game->mlx_ptr)
		ft_error(1);
	load_images(assets, game);
	render_map(game, assets);
	mlx_loop(game->mlx_ptr);
}