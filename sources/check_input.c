/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:37:58 by ahavu             #+#    #+#             */
/*   Updated: 2025/03/14 09:05:18 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_input(int argc, char *arg)
{
	if (argc != 2)
	{
		ft_putstr_fd("\033[91mError\nInvalid argument!☝️\n\033[0m", 2);
		exit(EXIT_FAILURE);
	}
	if (ft_strlen(arg) >= 5)
	{
		arg = arg + ft_strlen(arg) - 4;
		if (ft_strncmp(arg, ".ber", 4))
		{
			ft_putstr_fd("\033[91mError\nMap needs to be .ber 🙄\n\033[0m", 2);
			exit(EXIT_FAILURE);
		}
	}
	else if (ft_strlen(arg) < 5)
	{
		ft_putstr_fd("\033[91mError\nInvalid argument!☝️\n\033[0m", 2);
		exit(EXIT_FAILURE);
	}
}

static void	validate_symbols(t_game *game)
{
	if (game->exit > 1)
		ft_error(3, game);
	else if (game->player > 1)
		ft_error(4, game);
	else if (game->exit == 0)
		ft_error(5, game);
	else if (game->player == 0)
		ft_error(6, game);
	else if (game->coll < 1)
		ft_error(7, game);
}

void	count_symbols(t_game *game)
{
	int	i;
	int	k;

	i = 0;
	if (!game->map[i])
		ft_error(11, game);
	while (game->map[i])
	{
		k = 0;
		while (game->map[i][k])
		{
			if (game->map[i][k] == 'E')
				game->exit++;
			else if (game->map[i][k] == 'P')
				game->player++;
			else if (game->map[i][k] == 'C')
				game->coll++;
			else if (game->map[i][k] != '0' && game->map[i][k] != '1')
				ft_error(9, game);
			k++;
		}
		i++;
	}
	validate_symbols(game);
}
