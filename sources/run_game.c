/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:32:50 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/07 16:34:08 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *game, t_assets *assets)
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
					x * TILE, y * TILE);
			if (game->map[y][x] != '1')
				mlx_image_to_window(game->mlx_ptr, assets->floor, 
					x * TILE, y * TILE);
			if (game->map[y][x] == 'P')
				mlx_image_to_window(game->mlx_ptr, assets->player, 
					x * TILE, y * TILE);
			else if (game->map[y][x] == 'E')
				mlx_image_to_window(game->mlx_ptr, assets->exit_closed, 
					x * TILE, y * TILE);
			else if (game->map[y][x] == 'C')
				mlx_image_to_window(game->mlx_ptr, assets->coll, 
					x * TILE, y * TILE);
			x++;
		}
		y++;
	}
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

static void key_hook(mlx_key_data_t keydata, void *param)
{
	t_game		*game;
    t_assets	*assets;

	game = ((t_game **)param)[0];
	assets = ((t_assets **)param)[1];
	if (keydata.key == MLX_KEY_ESCAPE)
		ft_exit(game);
	else if (keydata.key == MLX_KEY_W)
		move_player(game, assets, 'y', UP);
	else if (keydata.key == MLX_KEY_A)
		move_player(game, assets, 'x', LEFT);
	else if (keydata.key == MLX_KEY_S)
		move_player(game, assets, 'y', DOWN);
	else if (keydata.key == MLX_KEY_D)
		move_player(game, assets, 'x', RIGHT);
}

void	run_game(t_game *game)
{
	t_assets	*assets;
	void		*param[2];

	assets = malloc(sizeof(t_assets));
	if (!assets)
		ft_error(1);
	game->mlx_ptr = mlx_init(WIDTH, HEIGHT, "FEED THE VAMP", false);
	if (!game->mlx_ptr)
		ft_error(1);
	load_images(assets, game);
	render_map(game, assets);
	param[0] = game;
	param[1] = assets;
	mlx_key_hook(game->mlx_ptr, key_hook, param);
	mlx_loop(game->mlx_ptr);
}
