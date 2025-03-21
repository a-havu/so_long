/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:12:19 by ahavu             #+#    #+#             */
/*   Updated: 2025/03/14 09:05:34 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	check_input(argc, argv[1]);
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		ft_error(1, game);
	game->moves = 1;
	check_map(argv[1], game);
	count_symbols(game);
	parse_map(game);
	run_game(game);
	return (EXIT_SUCCESS);
}
