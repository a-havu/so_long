/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:12:19 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/29 13:56:46 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

int main(int argc, char **argv)
{
	mlx_t	*mlx;
	
	mlx = mlx_init(WIDTH, HEIGHT, "so_long_attack_of_the_perfumes", true);
	//take a .ber file as argument
	get_next_line(argv[1]); // read the map with gnl
	mlx_new_window();
	mlx_loop(mlx);
	

	mlx_terminate(mlx); // 	Destroy and clean up all images and mlx resources.
}