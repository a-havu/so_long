/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:12:19 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/07 17:40:32 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_game_struct(t_game *game)
{
	game->exit = 0;
	game->player = 0;
	game->coll = 0;
	game->collected = 0;
	game->moves = 1;
	game->x = 0;
	game->y = 0;
}

int main(int argc, char **argv)
{
	t_game	*game;
	
	game = malloc(sizeof(t_game));
	check_input(argc, argv[1]);
	init_game_struct(game);
	check_map(argv[1], game);
	check_symbols(game);
	parse_map(game);
	ft_printf("Map x: %d, map y: %d\n", game->x, game->y);
	ft_printf("Player x: %d, player y: %d\n", game->p_x, game->p_y);
	run_game(game);
	return (EXIT_SUCCESS);
}


//Jules is using key_hook, close_hook and loop_hook