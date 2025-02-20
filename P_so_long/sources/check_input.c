/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:37:58 by ahavu             #+#    #+#             */
/*   Updated: 2025/02/20 09:36:34 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_input(int argc, char *arg)
{
	if (argc > 2)
	{
		ft_putstr_fd("\033[91mError\nInvalid argument!☝️\n\033[0m", 2);
		exit(EXIT_FAILURE);
	}
	if (argc < 2)
	{
		ft_putstr_fd("\033[91mError\nGive a .ber file 🙄\n\033[0m", 2);
		exit(EXIT_FAILURE);
	}
	if (ft_strlen(arg) >= 5)
	{
		arg = arg + ft_strlen(arg) - 4;
		if (ft_strncmp(arg, ".ber", 4))
		{
			ft_putstr_fd("\033[91mError\nGive a .ber file 🙄\n\033[0m", 2);
			exit(EXIT_FAILURE);
		}
	}
	else if (ft_strlen(arg) < 5)
	{
		ft_putstr_fd("\033[91mError\nGive a .ber file 🙄\n\033[0m", 2);
		exit(EXIT_FAILURE);
	}
}

static void	validate_symbols(t_game *game)
{
	if (game->exit > 1)
		ft_error(3, game);
	else if (game->player > 1)
		ft_error(4, game);
	else if (game->exit == 0)
		ft_error(5, game);
	else if (game->player == 0)
		ft_error(6, game);
	else if (game->coll < 1)
		ft_error(7, game);
}

void	check_symbols(t_game *game)
{
	int	i;
	int	k;

	i = 0;
	if (!game->map[i])
		ft_error(11, game);
	while (game->map[i])
	{
		k = 0;
		while (game->map[i][k])
		{
			if (game->map[i][k] == 'E')
				game->exit++;
			else if (game->map[i][k] == 'P')
				game->player++;
			else if (game->map[i][k] == 'C')
				game->coll++;
			else if (game->map[i][k] != '0' && game->map[i][k] != '1')
				ft_error(9, game);
			k++;
		}
		i++;
	}
	validate_symbols(game);
}

static void	check_x_and_y(t_game *game)
{
	if ((game->x * TILE) > WIDTH || (game->y * TILE) > HEIGHT)
	{
		ft_printf("\033[91mSorry, the developer lacks viewport/resize skills 😔 ");
		ft_printf("The map is too large to fit in one window 😔😔\n");
		ft_printf("The allowed width is %d ", WIDTH);
		ft_printf("and height %d. ", HEIGHT); 
		ft_printf("Try again with a smaller map? 🥹\n\033[0m");
		exit(EXIT_FAILURE);
	}
}

void	check_map(char *arg, t_game *game)
{
	char	*line;
	int		fd;

	fd = open(arg, O_RDONLY);
	if (fd == -1)
		ft_error(8, game);
	line = NULL;
	game->map = ft_calloc(100, sizeof(char *));
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strchr(line, '\n'))
			*ft_strchr(line, '\n') = '\0';
		if (game->y == 0)
			game->x = ft_strlen(line);
		if (game->x != ft_strlen(line))
			ft_error(8, game);
		game->map[game->y] = line;
		game->y++;
	}
	game->map[game->y] = NULL;
	check_x_and_y(game);
	close(fd);
}
