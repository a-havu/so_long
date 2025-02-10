/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:32:50 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/10 16:05:33 by ahavu            ###   ########.fr       */
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

void	render_assets(t_game *game, t_assets *assets, int y)
{
	int	x;
	int	p;

	p = 0;
	while(game->map[y])
	{
		x = 1;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
				mlx_image_to_window(game->mlx_ptr, assets->player,
					x * TILE, y * TILE);
			else if (game->map[y][x] == 'E')
			{
				mlx_image_to_window(game->mlx_ptr, assets->exit_closed,
					x * TILE, y * TILE);
				mlx_image_to_window(game->mlx_ptr, assets->exit_open,
					x * TILE, y * TILE);
				game->exit_x = x;
				game->exit_y = y;
			}
			else if (game->map[y][x] == 'C')
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
	assets->exit_open->instances->enabled = false;
}

static void	load_images(t_assets *assets, t_game *game)
{
	assets->wall_t = mlx_load_png(WALL);
	assets->floor_t = mlx_load_png(FLOOR);
	assets->coll_t = mlx_load_png(COLL);
	assets->exit_closed_t = mlx_load_png(EXIT_CLOSED);
	assets->exit_open_t = mlx_load_png(EXIT_OPEN);
	assets->puddle_t = mlx_load_png(PUDDLE);
	assets->player_t = mlx_load_png(PLAYER);
	assets->wall = mlx_texture_to_image(game->mlx_ptr, assets->wall_t);
	assets->floor = mlx_texture_to_image(game->mlx_ptr, assets->floor_t);
	assets->coll = mlx_texture_to_image(game->mlx_ptr, assets->coll_t);
	assets->player = mlx_texture_to_image(game->mlx_ptr, assets->player_t);
	assets->puddle = mlx_texture_to_image(game->mlx_ptr, assets->puddle_t);
	assets->exit_closed = mlx_texture_to_image(game->mlx_ptr,
			assets->exit_closed_t);
	assets->exit_open = mlx_texture_to_image(game->mlx_ptr,
			assets->exit_open_t);
	assets->player = mlx_texture_to_image(game->mlx_ptr, assets->player_t);
}

static void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game		*game;
	t_assets	*assets;

	game = ((t_game **)param)[0];
	assets = ((t_assets **)param)[1];
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_exit(game, 0);
	else if (keydata.key == MLX_KEY_W
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_player(game, assets, 'y', UP);
	else if (keydata.key == MLX_KEY_A
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_player(game, assets, 'x', LEFT);
	else if (keydata.key == MLX_KEY_S
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_player(game, assets, 'y', DOWN);
	else if (keydata.key == MLX_KEY_D
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_player(game, assets, 'x', RIGHT);
}

void	run_game(t_game *game)
{
	t_assets	*assets;
	void		*param[2];

	assets = malloc(sizeof(t_assets));
	if (!assets)
		ft_error(1, game);
	game->mlx_ptr = mlx_init(WIDTH, HEIGHT, "FEED THE VAMP", 1);
	if (!game->mlx_ptr)
		ft_error(1, game);
	load_images(assets, game);
	render_map(game, assets);
	render_assets(game, assets, 1);
	param[0] = game;
	param[1] = assets;
	mlx_key_hook(game->mlx_ptr, key_hook, param);
	mlx_loop(game->mlx_ptr);
}
