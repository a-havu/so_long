/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:14:10 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/06 17:36:38 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIDTH 600
# define HEIGHT 600

# include "libft_plus.h"
# include "libftprintf.h"
# include "MLX42.h"
# include <math.h>
# include <fcntl.h>

# define WALL			"assets/ruusut3.png"
# define FLOOR			"assets/grass.png"
# define COLL			"assets/nobleman.png"
# define PLAYER			"assets/vampire.png"
# define EXIT_CLOSED	"assets/closed_coffin.png"
# define EXIT_OPEN		"assets/open_coffin.png"

# define TILE_SIZE 64

typedef struct s_assets
{
	mlx_texture_t	*wall_t;
	mlx_texture_t	*floor_t;
	mlx_texture_t	*coll_t;
	mlx_texture_t	*player_t;
	mlx_texture_t	*exit_closed_t;
	mlx_texture_t	*exit_open_t;
	mlx_image_t		*wall;
	mlx_image_t		*floor;
	mlx_image_t		*coll;
	mlx_image_t		*player;
	mlx_image_t		*exit_closed;
	mlx_image_t		*exit_open;
} t_assets;

typedef struct s_game
{
	char		**map;
	char		**map_cpy;
	mlx_t		*mlx_ptr;
	int			exit;
	int			player;
	int			coll;
	int			player_x;
	int			player_y;
	size_t		x;
	size_t		y;
} t_game;

void	check_input(int argc, char *argv);
void	check_map(char *arg, t_game *game);
void	check_symbols(t_game *game);
void	ft_error(int num);
void	ft_error_free(int num, t_game *game);
void	parse_map(t_game *game);
void	run_game(t_game *game);

#endif