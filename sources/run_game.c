/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:32:50 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/11 15:26:48 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}

/*static void	resize_images(t_game *game, t_assets *assets)
{
	uint32_t	new_tile;
	uint32_t	percent;

	percent = WIDTH / game->x;
	new_tile = (percent * 100)/TILE;
	mlx_resize_image(assets->coll, new_tile, new_tile);
	mlx_resize_image(assets->player, new_tile, new_tile);
	mlx_resize_image(assets->wall, new_tile, new_tile);
	mlx_resize_image(assets->floor, new_tile, new_tile);
	mlx_resize_image(assets->exit_open, new_tile, new_tile);
	mlx_resize_image(assets->exit_closed, new_tile, new_tile);
	mlx_resize_image(assets->puddle, new_tile, new_tile);
	game->tile = new_tile;
}*/

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
	//if ((game->y * TILE) > HEIGHT || (game->x * TILE) > WIDTH)
	//	resize_images(game, assets);
	if ((game->y * TILE) < HEIGHT || (game->x * TILE) < WIDTH)
		mlx_set_window_size(game->mlx_ptr, (int32_t)(game->x * TILE),
		(int32_t)(game->y * TILE));
	load_images(assets, game);
	delete_textures(assets);
	render_map(game, assets);
	render_collectibles(game, assets);
	render_exits(game, assets);
	render_player(game, assets);
	param[0] = game;
	param[1] = assets;
	mlx_put_string(game->mlx_ptr, "Vamp is hungry!!", 30, 30);
	mlx_key_hook(game->mlx_ptr, key_hook, param);
	mlx_loop(game->mlx_ptr);
}
