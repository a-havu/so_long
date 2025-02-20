/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:02:07 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/11 10:44:58 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(t_game *game, int message, t_assets *assets)
{
	if (message == 1)
		ft_printf("Have a good day's slumber with a belly full of blood!✨🩸\n");
	if (message == 0)
		ft_printf("You quit 😔 The Vamp remains hungry 😔😔\n");
	clean_up(game);
	free(assets);
	exit(EXIT_SUCCESS);
}
