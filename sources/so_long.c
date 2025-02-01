/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:12:19 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/01 16:14:39 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	//mlx_t	*mlx;
	t_game	*game;
	
	game = NULL;
	if (argc != 2)
	{
		ft_error(2);
		exit(EXIT_FAILURE);
	}
	if (!check_filetype(argv[1]))
		ft_error(0);
	initialize_map(argv[1], game);
	parse_map(game);
		/*mlx = mlx_init(WIDTH, HEIGHT, "so_long", true); // initialize the thing
	if (!mlx)
	{
		ft_error(1);
		exit(EXIT_FAILURE);
	}*/
	
	/*mlx_new_window();
	mlx_image_to_window(mlx, img, 80, 80);
	mlx_loop(mlx);
	

	mlx_terminate(mlx); // 	Destroy and clean up all images and mlx resources.*/
	return (EXIT_SUCCESS);
}

//Jules is using key_hook, close_hook and loop_hook