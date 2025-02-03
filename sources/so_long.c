/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:12:19 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/03 16:24:34 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	run_game(t_game *game)
{
	game->mlx_ptr = mlx_init(WIDTH, HEIGHT, "so_long", true); // initialize the thing
	if (!game->mlx_ptr)
	{
		ft_error(1);
		exit(EXIT_FAILURE);
	}
	/*mlx_new_window();
	mlx_image_to_window(mlx, img, 80, 80);
	mlx_loop(mlx);?*/
}

static void	init_game_struct(t_game *game)
{
	game->map = NULL;
	game->map_cpy = NULL;
	game->exit = 0;
	game->player = 0;
	game->coll = 0;
	game->coll_check = 0;
	game->x = 0;
	game->y = 0;
}

int main(int argc, char **argv)
{
	t_game	*game;
	
	game = NULL;
	check_input(argc, argv[1]);
	init_game_struct(game);
	initialize_map(argv[1], game);
	parse_map(game);
	run_game(game);
	mlx_terminate(game->mlx_ptr); // Destroy and clean up all images and mlx resources.*/
	return (EXIT_SUCCESS);
}


//Jules is using key_hook, close_hook and loop_hook