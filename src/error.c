/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkalkan <emkalkan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:24:44 by emkalkan          #+#    #+#             */
/*   Updated: 2024/02/18 17:58:50 by emkalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error1(t_game *game)
{
	int	i;

	if (!game->mlx_ptr || !game->win)
	{
		ft_printf("Error initializing MiniLibX OR Win\n");
		free_game(game);
		exit(EXIT_FAILURE);
	}
	if (game->bgx <= game->bgy)
	{
		ft_printf("Error Window not rectangular\n");
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
		ft_printf("Error in map_check_walls_outside\n");
		free_game(game);
		exit(EXIT_FAILURE);
	}
	else if (!(check_for_path(game, game->positions_p[0].x,
				game->positions_p[0].y)))
	{
		ft_printf("Error floodfill\n");
		free_game(game);
		exit(EXIT_FAILURE);
	}
}

void error3(t_game *game)
{
	if (game->num_positions_e == 0)
	{
		ft_printf("Error no exit\n");
		free_gamechars(game);
		exit(EXIT_FAILURE);
	}
	if (game->num_positions_p == 0)
	{
		ft_printf("Error no player\n");
		free_gamechars(game);
		exit(EXIT_FAILURE);
	}
	if (game->num_positions_c < 0)
	{
		ft_printf("Error no coins\n");
		free_gamechars(game);
		exit(EXIT_FAILURE);
	}
}

int check_file_format(const char *file_name)
{
    const char *file_extension = strrchr(file_name, '.');
    
    if (file_extension != NULL && strcmp(file_extension, ".ber") == 0)
        return 1;
    else
        return 0;
}
