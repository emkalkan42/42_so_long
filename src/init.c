/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkalkan <emkalkan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:09:27 by emkalkan          #+#    #+#             */
/*   Updated: 2024/02/16 00:10:23 by emkalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_pointers(t_game *game)
{
	// Initialize pointers to NULL
	game->mlx_ptr = NULL;
	game->win = NULL;
	game->img_playerr = NULL;
	game->img_playerl = NULL;
	game->img_playerf = NULL;
	game->img_playerb = NULL;
	game->img_bgd = NULL;
	game->img_wall = NULL;
	game->img_ball = NULL;
	game->img_exit = NULL;
}

void	init_integers(t_game *game)
{
	// Initialize integer variables to 0
	game->count = 0;
	game->charsize = 0;
	game->ppostionx = 0;
	game->ppostiony = 0;
	game->x = 0;
	game->y = 0;
	game->bgx = 0;
	game->bgy = 0;
	game->collectedcount = 0;
	game->ballcount = 0;
	game->floodfillcount = 0;
	game->tmp_exit_count = 0;
}

void	init_arrays(t_game *game)
{
	// Initialize arrays and their corresponding counters to 0
	memset(game->collected_flags, 0, sizeof(game->collected_flags));
	memset(game->positions_0, 0, sizeof(game->positions_0));
	memset(game->positions_1, 0, sizeof(game->positions_1));
	memset(game->positions_C, 0, sizeof(game->positions_C));
	memset(game->positions_X, 0, sizeof(game->positions_X));
	memset(game->positions_E, 0, sizeof(game->positions_E));
	memset(game->positions_P, 0, sizeof(game->positions_P));
}

void	init_counters(t_game *game)
{
	// Initialize the number of positions to 0
	game->num_positions_0 = 0;
	game->num_positions_1 = 0;
	game->num_positions_C = 0;
	game->num_positions_F = 0;
	game->num_positions_X = 0;
	game->num_positions_E = 0;
	game->num_positions_P = 0;
}
