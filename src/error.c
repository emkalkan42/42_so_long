/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkalkan <emkalkan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:24:44 by emkalkan          #+#    #+#             */
/*   Updated: 2024/02/16 00:11:13 by emkalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error1(t_game *game)
{
	int	i;

	if (!game->mlx_ptr)
	{
		ft_printf("Error initializing MiniLibX\n");
		free_game(game);
		exit(EXIT_FAILURE);
	}
	if (game->bgx <= game->bgy)
	{
		ft_printf("Error Window not rectangular\n");
		free_game(game);
		exit(EXIT_FAILURE);
	}
	if (!game->win)
	{
		ft_printf("Error creating window\n");
		free_game(game);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < MAX_BALLS)
	{
		game->collected_flags[i] = 0;
		i++;
	}
}

void	error2(t_game *game)
{
	if (map_check_walls_outside(game) != 0)
	{
		// Handle the error or exit the program
		ft_printf("Error in map_check_walls_outside\n");
		free_game(game);
		exit(EXIT_FAILURE);
	}
	else if (!(check_for_path(game, game->positions_P[0].x,
				game->positions_P[0].y)))
	{
		// Handle the error or exit the program
		ft_printf("Error floodfill\n");
		free_game(game);
		exit(EXIT_FAILURE);
	}
}
