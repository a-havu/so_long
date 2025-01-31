/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahavu <ahavu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:01:39 by ahavu             #+#    #+#             */
/*   Updated: 2025/01/31 16:36:04 by ahavu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int num)
{
	if (num == 0)
		ft_printf("You need to give a .ber file as argument🙄");
	else if (num == 1)
		ft_printf("Oh no! Initializing failed😤😤🥺");
	else if (num == 2)
		ft_printf("Only one argument allowed!☝️");
	else if (num == 3)
		ft_printf("Too many exits!!!🙅‍♀️🙅‍♀️");
	else if (num == 4)
		ft_printf("Too many players honey! It's not a co-op...");
	else if (num == 5)
		ft_printf("You need to have an exit...🤸‍♀️");
	else if (num == 6)
		ft_printf("Can't play a game with no players😔");
	else if (num == 7)
		ft_printf("We need something to collect darling 🤑");
	exit(EXIT_FAILURE);
}
