/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:01:39 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/06 17:18:39 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int num)
{
	if (num == 0)
		ft_putstr_fd("Error\nYou need to give a .ber file as argument🙄\n", 2);
	else if (num == 1)
		ft_putstr_fd("Error\nOh no! Initializing failed😤😤🥺\n", 2);
	else if (num == 2)
		ft_putstr_fd("Error\nInvalid argument!☝️\n", 2);
	else if (num == 3)
		ft_putstr_fd("Error\nToo many exits!!!🙅🙅\n", 2);
	else if (num == 4)
		ft_putstr_fd("Error\nToo many players! It's not a co-op...\n", 2);
	else if (num == 5)
		ft_putstr_fd("Error\nYou need to have an exit...🤸\n", 2);
	else if (num == 6)
		ft_putstr_fd("Error\nCan't play a game with no players😔\n", 2);
	else if (num == 7)
		ft_putstr_fd("Error\nYou need something to collect🤑\n", 2);
	else if (num == 8)
		ft_putstr_fd("Error\nYour map's not valid💅\n", 2);
	else if (num == 9)
		ft_putstr_fd("Error\nUnknown character found!!!👽\n", 2);
	else if (num == 10)
		ft_putstr_fd("Error\nYou're trapped!!!😱\n", 2);
	else if (num == 11)
		ft_putstr_fd("Error\nEmpty map💔\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_error_free(int num, t_game *game)
{
	int	i;

	i = 0;
	if (num == 1)
		ft_putstr_fd("Error\nThere's no memory or smth, smh🙄\n", 2);
	else if (num == 2)
		ft_putstr_fd("Error\nSomething went wrong with the graphics😔\n", 2);
	while (game->map[i])
	{
		free(game->map[i]);
		game->map[i] = NULL;
		i++;
	}
	i = 0;
	while (game->map_cpy[i])
	{
		free(game->map_cpy[i]);
		game->map_cpy[i] = NULL;
		i++;
	}
	free(game->map);
	free(game);
	exit(EXIT_FAILURE);
}
