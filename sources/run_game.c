/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:32:50 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/23 10:31:38 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_garlic(t_assets *assets, t_game *game)
{
	assets->garlic_t = mlx_load_png(GARLIC);
	if (!assets->garlic_t)
		ft_error_assets(1, game, assets);
	assets->garlic = mlx_texture_to_image(game->mlx_ptr, assets->garlic_t);
	if (!assets->garlic)
		ft_error_assets(1, game, assets);
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
	if (!assets->wall_t || !assets-> floor_t || !assets->coll_t
		|| !assets-> exit_closed_t || !assets-> exit_open_t
		|| !assets->puddle_t || !assets->player_t)
		ft_error_assets(1, game, assets);
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
	if (!assets->wall || !assets->floor || !assets->exit_closed
		|| !assets->exit_open || !assets->puddle || !assets->player)
		ft_error_assets(1, game, assets);
	load_garlic(assets, game);
}

static void	delete_textures(t_assets *assets)
{
	mlx_delete_texture(assets->wall_t);
	mlx_delete_texture(assets->floor_t);
	mlx_delete_texture(assets->coll_t);
	mlx_delete_texture(assets->exit_closed_t);
	mlx_delete_texture(assets->exit_open_t);
	mlx_delete_texture(assets->puddle_t);
	mlx_delete_texture(assets->player_t);
	mlx_delete_texture(assets->garlic_t);
}

static void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game		*game;
	t_assets	*assets;

	game = ((t_game **)param)[0];
	assets = ((t_assets **)param)[1];
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		ft_exit(game, 0, assets);
	else if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_player(game, assets, 'y', UP);
	else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_player(game, assets, 'x', LEFT);
	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_player(game, assets, 'y', DOWN);
	else if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_player(game, assets, 'x', RIGHT);
	else if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
		destroy_garlic(game, assets);
}

void	run_game(t_game *game)
{
	t_assets	*assets;
	void		*param[2];

	assets = malloc(sizeof(t_assets));
	if (!assets)
		ft_error(1, game);
	game->mlx_ptr = mlx_init((int32_t)(game->x * TILE),
			(int32_t)(game->y * TILE), "FEED THE VAMP", 0);
	if (!game->mlx_ptr)
		ft_error(1, game);
	load_images(assets, game);
	delete_textures(assets);
	render_map(game, assets);
	render_collectibles(game, assets);
	render_exits(game, assets);
	render_player(game, assets);
	ft_printf("floor count: %d\n", assets->floor->count);
	if (assets->floor->count > 1)
		render_garlic(game, assets);
	param[0] = game;
	param[1] = assets;
	mlx_key_hook(game->mlx_ptr, key_hook, param);
	mlx_loop(game->mlx_ptr);
}
