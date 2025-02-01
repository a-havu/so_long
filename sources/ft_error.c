/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:01:39 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/01 14:15:07 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int num)
{
	if (num == 0)
		ft_putstr_fd("You need to give a .ber file as argument🙄", 2);
	else if (num == 1)
		ft_putstr_fd("Oh no! Initializing failed😤😤🥺", 2);
	else if (num == 2)
		ft_putstr_fd("Only one argument allowed!☝️", 2);
	else if (num == 3)
		ft_putstr_fd("Too many exits!!!🙅‍♀️🙅‍♀️", 2);
	else if (num == 4)
		ft_putstr_fd("Too many players honey! It's not a co-op...", 2);
	else if (num == 5)
		ft_putstr_fd("You need to have an exit...🤸‍♀️", 2);
	else if (num == 6)
		ft_putstr_fd("Can't play a game with no players😔", 2);
	else if (num == 7)
		ft_putstr_fd("We need something to collect darling 🤑", 2);
	else if (num == 8)
		ft_putstr_fd("Your map's not valid💅", 2);
	else if (num == 9)
	exit(EXIT_FAILURE);
}

void	ft_error_free(int num, t_game *game)
{
	int	i;

	i = 0;
	if (num == 1)
	{
		while (game->map)
		{
			free(game->map[i]);
			game->map[i] = NULL;
			i++;
		}
		ft_putstr_fd("There's no memory or smth, smh🙄", 2);
	}
	exit(EXIT_FAILURE);
	
}
