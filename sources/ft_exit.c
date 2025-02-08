/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:02:07 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/08 12:06:47 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(t_game *game, int message)
{
	clean_up(game);
	mlx_terminate(game->mlx_ptr);
	if (message == 1)
		ft_printf("Have a good day's slumber with a belly full of blood!✨🩸\n");
	if (message == 0)
		ft_printf("You quit 😔 The Vamp remains hunrgy 😔😔\n");
	exit(EXIT_SUCCESS);
}
