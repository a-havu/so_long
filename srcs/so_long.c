/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:12:19 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/27 11:10:16 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

int main(int argc, char **argv)
{
	mlx_init();
	//take a .ber file as argument
	get_next_line(argv[1]);
	mlx_new_window() 
	


	mlx_delete_image()  //delete and free everything with these three
	mlx_destroy_window()
	mlx_destroy_display()
}