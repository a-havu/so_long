/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:26:02 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/07 17:44:35 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	validate_movement(t_game *game, char ax, int dir)
{
	if (ax == 'y')
	{
		if (game->map[game->p_y][game->p_x + dir] != '1')
		{
			if (game->map[game->p_y][game->p_x + dir] == 'E'
			&& game->collected != game->coll)
				ft_printf("More blood is needed before slumbering!\n");
			else
			{	
				game->map[game->p_y][game->p_x] = '0';
				game->p_y += dir;
			}
		}
	}
	else if (ax == 'x')
	{
		if (game->map[game->p_y + dir][game->p_x] != '1')
		{
			if (game->map[game->p_y + dir][game->p_x] == 'E'
			&& game->collected != game->coll)
				ft_printf("More blood is needed before slumbering!\n");
			else
			{
				game->map[game->p_y][game->p_x] = '0';
				game->p_x += dir;
			}
		}
	}
}

void	move_player(t_game *game, t_assets *assets, char ax, int dir)
{
	validate_movement(game, ax, dir);
	if (game->map[game->p_y][game->p_x] == 'C')
	{
		game->map[game->p_y][game->p_x] = '0';
		render_map(game, assets);
		game->collected++;
	}
	game->map[game->p_y][game->p_x] = 'P';
	render_map(game, assets);
	ft_printf("BAT! You've flown %d times\n", game->moves++);
}
