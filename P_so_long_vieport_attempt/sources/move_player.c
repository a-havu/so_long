/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:26:02 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/19 15:36:00 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	collect(t_game *game, t_assets *assets)
{
	int	i;

	i = assets->coll->count;
	game->map[game->p_y][game->p_x] = '0';
	while (i--)
	{
	 	if (assets->coll->instances[i].x == assets->player->instances->x
			&& assets->coll->instances[i].y == assets->player->instances->y)
		{
			assets->coll->instances[i].enabled = false;
			assets->puddle->instances[i].enabled = true;
		}
	}
	game->collected++;
	if (game->collected == game->coll)
	{
		assets->exit_open->instances->enabled = true;
		assets->exit_closed->instances->enabled = false;
	}
}

static void	validate_movement_y(t_game *game, int dir, t_assets *assets)
{
	if (game->map[game->p_y + dir][game->p_x] != '1')
	{
		if (game->map[game->p_y + dir][game->p_x] == 'E'
		&& game->collected >= game->coll)
			ft_exit(game, 1, assets);
		if (dir == -1)
		{
			assets->player->instances[0].y -= TILE;
			game->p_y--;
			if (game->map[game->p_y][game->p_x] == 'C')
				collect(game, assets);
			ft_printf("BAT! You've flown %d times\n", game->moves++);
		}
		else
		{
			assets->player->instances[0].y += TILE;
			game->p_y++;
			if (game->map[game->p_y][game->p_x] == 'C')
				collect(game, assets);
			ft_printf("BAT! You've flown %d times\n", game->moves++);
		}
	}
}

static void	validate_movement_x(t_game *game, int dir, t_assets *assets)
{
	if (game->map[game->p_y][game->p_x + dir] != '1')
	{
		if (game->map[game->p_y][game->p_x + dir] == 'E'
		&& game->collected >= game->coll)
			ft_exit(game, 1, assets);
		if (dir == 1)
		{
			assets->player->instances[0].x += TILE;
			game->p_x++;
			if (game->map[game->p_y][game->p_x] == 'C')
				collect(game, assets);
			ft_printf("BAT! You've flown %d times\n", game->moves++);
		}
		else
		{
			assets->player->instances[0].x -= TILE;
			game->p_x--;
			if (game->map[game->p_y][game->p_x] == 'C')
				collect(game, assets);
			ft_printf("BAT! You've flown %d times\n", game->moves++);
		}
	}
}

static void	update_viewport(t_game *game)
{
    game->viewport_x = game->p_x * TILE - WIDTH / 2;
    game->viewport_y = game->p_y * TILE - HEIGHT / 2;

    if (game->viewport_x < 0)
        game->viewport_x = 0;
    if (game->viewport_x > (game->x * TILE - WIDTH))
        game->viewport_x = game->x * TILE - WIDTH;
		
    if (game->viewport_y < 0)
        game->viewport_y = 0;
    if (game->viewport_y > (game->y * TILE - HEIGHT))
        game->viewport_y = game->y * TILE - HEIGHT;
}


void	move_player(t_game *game, t_assets *assets, char ax, int dir)
{
	if (ax == 'y')
		validate_movement_y(game, dir, assets);
	else if (ax == 'x')
		validate_movement_x(game, dir, assets);
	if (game->viewport_mode)
		update_viewport(game);
}
