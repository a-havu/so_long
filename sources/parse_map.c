/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:17:34 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/01 16:55:04 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_map(t_game *game)
{
	int i;
	
	i = 0;
	while (game->map[0])
	{
		if (game->map[0][i] != '1')
			ft_error(8);
		i++;
	}
	i = 0;
	while (game->map)
	{
		if (game->map[i][0] != '1' && game->map[i][game->x] != '1')
			ft_error(8);
		i++;
	}
	i = 0;
	while (game->map[game->y])
	{
		if (game->map[game->y][i] != '1')
			ft_error(8);
		i++;
	}
}
