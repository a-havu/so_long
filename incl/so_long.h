/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:14:10 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/07 16:05:07 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIDTH 832
# define HEIGHT 448

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

# define TILE 64

# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53

# define UP -1
# define LEFT -1
# define DOWN 1
# define RIGHT 1

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
	int			collected;
	int			p_x; //player's position on x axis
	int			p_y; //player's position on y axis
	int			moves;
	size_t		x;
	size_t		y;
} t_game;

void	check_input(int argc, char *argv);
void	check_map(char *arg, t_game *game);
void	check_symbols(t_game *game);
void	ft_error(int num);
void	ft_error_free(int num, t_game *game);
void	ft_exit(t_game *game);
void	move_player(t_game *game, t_assets *assets, char ax, int dir);
void	parse_map(t_game *game);
void	render_map(t_game *game, t_assets *assets);
void	run_game(t_game *game);

#endif