/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:02:07 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/25 09:04:11 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(t_game *game, int message, t_assets *assets)
{
	if (message == 0)
		ft_printf("\033[96mYou quit 😔 The Vamp remains hungry 😔😔\n\033[0m");
	if (message == 1)
	{
		ft_printf("\033[96mHave a good day's slumber ");
		ft_printf("with a belly full of blood!✨🩸\n\033[0m");
	}
	if (message == 2)
		ft_printf("\033[96mNOOOOOO!!! YOU TOUCHED GARLIC!!! 💀💀💀😭😭😭\n\033[0m");
	clean_up(game);
	free(assets);
	exit(EXIT_SUCCESS);
}

void	destroy_garlic(t_game *game, t_assets *assets)
{
	size_t	i;
	int		garlic_x;
	int		garlic_y;

	i = 0;
	while (i < assets->garlic->count)
	{
		garlic_x = assets->garlic->instances[i].x / TILE;
		garlic_y = assets->garlic->instances[i].y / TILE;
		if ((garlic_x == game->p_x + 1 && garlic_y == game->p_y)
			|| (garlic_x == game->p_x - 1 && garlic_y == game->p_y)
			|| (garlic_x == game->p_x && garlic_y == game->p_y + 1)
			|| (garlic_x == game->p_x && garlic_y == game->p_y - 1))
		{
			assets->garlic->instances[i].enabled = false;
			ft_printf("\033[96mHA!! Take that you nasty garlic! 🦇💪💪\n\033[0m");
		}
		i++;
	}
}
