/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:20:18 by ahavu             #+#    #+#             */
/*   Updated: 2025/03/10 14:09:17 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_rows(char *arg, t_game *game)
{
	int		fd;
	int		rows;
	char	*line;

	rows = 0;
	line = NULL;
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		ft_error(8, game);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		rows++;
		free(line);
	}
	close(fd);
	return (rows);
}

static void	get_next_map_line(t_game *game, int fd, int rows)
{
	char	*line;

	line = NULL;
	game->map = ft_calloc(rows + 1, sizeof(char *));
	if (!game->map)
		ft_error(1, game);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strchr(line, '\n'))
			*ft_strchr(line, '\n') = '\0';
		if (game->y == 0)
			game->x = ft_strlen(line);
		game->map[game->y] = line;
		if (game->x != ft_strlen(line))
			ft_error(8, game);
		game->y++;
	}
	game->map[game->y] = NULL;
}

void	check_map(char *arg, t_game *game)
{
	int		fd;
	int		rows;

	rows = get_rows(arg, game);
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		ft_error(8, game);
	get_next_map_line(game, fd, rows);
	if ((game->x * TILE) > WIDTH || (game->y * TILE) > HEIGHT)
	{
		ft_printf("\033[91mSorry, the developer lacks resizing skills 😔. ");
		ft_printf("The map is too large to fit in one window 😔😔\n");
		ft_printf("The max allowed width is %d ", WIDTH);
		ft_printf("and height %d.\n", HEIGHT);
		ft_printf("(In tiles %d times %d", (WIDTH / TILE), (HEIGHT / TILE));
		ft_printf(" - your map was %d times %d)\n", game->x, game->y);
		ft_printf("Try again with a smaller map? 🥹🙏\n\033[0m");
		clean_up(game);
		exit(EXIT_FAILURE);
	}
	close(fd);
}
