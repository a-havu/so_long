/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:14:10 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/20 08:32:56 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIDTH 1000
# define HEIGHT 1000

# include "libft_plus.h"
# include "libftprintf.h"
# include "MLX42.h"
# include <math.h>
# include <fcntl.h>

# define WALL			"assets/shrub128.png"
# define FLOOR			"assets/grass128.png"
# define COLL			"assets/nobleman128.png"
# define PLAYER			"assets/vampire128_2.png"
# define EXIT_CLOSED	"assets/closed_coffin128.png"
# define EXIT_OPEN		"assets/open_coffin128.png"
# define PUDDLE			"assets/puddle_2.png"

# define TILE 128

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
	mlx_texture_t	*puddle_t;
	mlx_image_t		*wall;
	mlx_image_t		*floor;
	mlx_image_t		*coll;
	mlx_image_t		*player;
	mlx_image_t		*exit_closed;
	mlx_image_t		*exit_open;
	mlx_image_t		*puddle;
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
	int			p_x;
	int			p_y;
	int			moves;
	size_t		x;
	size_t		y;
	size_t		exit_x;
	size_t		exit_y;
	bool		viewport_mode;
	size_t		viewport_x;
	size_t		viewport_y;
	size_t		render_x;
	size_t		render_y;
} t_game;

void	check_input(int argc, char *argv);
void	check_map(char *arg, t_game *game);
void	check_symbols(t_game *game);
void	clean_up(t_game *game);
void	clean_assets(t_assets *assets);
void	ft_error(int num, t_game *game);
void	ft_error_assets(int num, t_game *game, t_assets *assets);
void	ft_exit(t_game *game, int message, t_assets *assets);
void	move_player(t_game *game, t_assets *assets, char ax, int dir);
void	parse_map(t_game *game);
void	render_collectibles(t_game *game, t_assets *assets);
void	render_exits(t_game *game, t_assets *assets);
void	render_map(t_game *game, t_assets *assets);
void	render_player(t_game *game, t_assets *assets);
void	run_game(t_game *game);

#endif