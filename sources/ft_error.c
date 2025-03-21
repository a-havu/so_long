/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:01:39 by ahavu             #+#    #+#             */
/*   Updated: 2025/03/14 09:03:37 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int num, t_game *game)
{
	if (num == 1)
		ft_putstr_fd("\033[91mError\nOh no! Initializing failed😤😤🥺\n\033[0m", 2);
	else if (num == 2)
		ft_putstr_fd("\033[91mError\nThere's no memory or smth, smh🙄\n\033[0m", 2);
	else if (num == 3)
		ft_putstr_fd("\033[91mError\nToo many exits!!!🙅🙅\n\033\033[0m", 2);
	else if (num == 4)
		ft_putstr_fd("\033[91mError\nExtra players! It's not a co-op\n\033[0m", 2);
	else if (num == 5)
		ft_putstr_fd("\033[91mError\nYou need to have an exit...🤸\n\033[0m", 2);
	else if (num == 6)
		ft_putstr_fd("\033[91mError\nCan't play with no players😔\n\033[0m", 2);
	else if (num == 7)
		ft_putstr_fd("\033[91mError\nYou need something to collect🤑\n\033[0m", 2);
	else if (num == 8)
		ft_putstr_fd("\033[91mError\nYour map's not valid💅\n\033[0m", 2);
	else if (num == 9)
		ft_putstr_fd("\033[91mError\nUnknown character found!!!👽\n\033[0m", 2);
	else if (num == 10)
		ft_putstr_fd("\033[91mError\nYou're trapped!!!😱\n\033[0m", 2);
	else if (num == 11)
		ft_putstr_fd("\033[91mError\nEmpty map💔\n\033[0m", 2);
	clean_up(game);
	exit(EXIT_FAILURE);
}

void	clean_images(t_game *game, t_assets *assets)
{
	if (assets->coll)
		mlx_delete_image(game->mlx_ptr, assets->coll);
	if (assets->garlic)
		mlx_delete_image(game->mlx_ptr, assets->garlic);
	if (assets->wall)
		mlx_delete_image(game->mlx_ptr, assets->wall);
	if (assets->player)
		mlx_delete_image(game->mlx_ptr, assets->player);
	if (assets->puddle)
		mlx_delete_image(game->mlx_ptr, assets->puddle);
	if (assets->exit_open)
		mlx_delete_image(game->mlx_ptr, assets->exit_open);
	if (assets->exit_closed)
		mlx_delete_image(game->mlx_ptr, assets->exit_closed);
	if (assets->floor)
		mlx_delete_image(game->mlx_ptr, assets->floor);
}

void	ft_error_assets(t_game *game, t_assets *assets)
{
	ft_putstr_fd("\033[91mError\n", 2);
	ft_putstr_fd("Something wrong with graphics💔📺💔\n\033[0m", 2);
	if (assets->coll_t)
		mlx_delete_texture(assets->coll_t);
	if (assets->garlic_t)
		mlx_delete_texture(assets->garlic_t);
	if (assets->wall_t)
		mlx_delete_texture(assets->wall_t);
	if (assets->player_t)
		mlx_delete_texture(assets->player_t);
	if (assets->puddle_t)
		mlx_delete_texture(assets->puddle_t);
	if (assets->exit_open_t)
		mlx_delete_texture(assets->exit_open_t);
	if (assets->exit_closed_t)
		mlx_delete_texture(assets->exit_closed_t);
	if (assets->floor_t)
		mlx_delete_texture(assets->floor_t);
	clean_images(game, assets);
	free(assets);
	clean_up(game);
	exit(EXIT_FAILURE);
}

static void	clean_map_copy(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_cpy[i])
	{
		free(game->map_cpy[i]);
		game->map_cpy[i] = NULL;
		i++;
	}
	free(game->map_cpy);
}

void	clean_up(t_game *game)
{
	int	i;

	if (game->map)
	{
		i = 0;
		while (game->map[i])
		{
			free(game->map[i]);
			game->map[i] = NULL;
			i++;
		}
		free(game->map);
	}
	if (game->map_cpy)
		clean_map_copy(game);
	if (game->mlx_ptr)
		mlx_terminate(game->mlx_ptr);
	if (game)
		free(game);
}
