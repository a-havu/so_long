/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:14:10 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/01 17:20:26 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIDTH 256
# define HEIGHT 256

# include "libft_plus.h"
# include "libftprintf.h"
# include "MLX42.h"
# include <math.h>
# include <fcntl.h>

# define WALL_XPM	"assets/sprites....."
# define FLOOR_XPM
# define COLL_XPM
# define PLAYER // and then possibly the directions? PLAYER_FRONT PLAYER_BACK etc
# define EXIT_CLOSED
# define EXIT_OPEN

/*typedef struct mlx
{
	void*		window; // the window itself
	void*		context; //Abstracted opengl data.
	int32_t		width; // w & h of window
	int32_t		height;
	double		delta_time; // The time difference between previous and current frame.
}	mlx_t;

typedef struct mlx_image
{
	const uint32_t	width;
	const uint32_t	height;
	uint8_t*		pixels; //The literal pixel data.
	mlx_instance_t*	instances; //An instance carries the X, Y, Z location data.
	int32_t			count; //The element count of the instances array.
	bool			enabled; //If true the image is drawn onto the screen, else it's not.
	void*			context; //Abstracted OpenGL data.
}	mlx_image_t;*/

typedef struct s_game
{
	char		**map;
	int			exit;
	int			player;
	int			coll;
	size_t		x;
	size_t		y;
	
} t_game;

int		check_filetype(char *arg);
void	ft_error(int num);
void	ft_error_free(int num, t_game *game);
void	initialize_map(char *arg, t_game *game);
void	parse_map(t_game *game);

#endif