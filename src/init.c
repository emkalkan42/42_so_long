/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkalkan <emkalkan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 20:09:27 by emkalkan          #+#    #+#             */
/*   Updated: 2024/02/21 14:50:17 by emkalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_pointers(t_game *game)
{
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
	memset(game->collected_flags, 0, sizeof(game->collected_flags));
	memset(game->positions_0, 0, sizeof(game->positions_0));
	memset(game->positions_1, 0, sizeof(game->positions_1));
	memset(game->positions_c, 0, sizeof(game->positions_c));
	memset(game->positions_x, 0, sizeof(game->positions_x));
	memset(game->positions_e, 0, sizeof(game->positions_e));
	memset(game->positions_p, 0, sizeof(game->positions_p));
}

void	init_counters(t_game *game)
{
	game->num_positions_0 = 0;
	game->num_positions_1 = 0;
	game->num_positions_c = 0;
	game->num_positions_x = 0;
	game->num_positions_e = 0;
	game->num_positions_p = 0;
}
