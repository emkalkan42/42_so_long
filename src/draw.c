/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkalkan <emkalkan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:28:40 by emkalkan          #+#    #+#             */
/*   Updated: 2024/02/16 00:41:06 by emkalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	draw_backgroundx(t_game *game) // 17 lines
{
	while (game->x < game->charsize * game->bgx && game->y < game->charsize
		* game->bgy)
	{
		if (game->x >= game->charsize * game->bgx - game->charsize)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win, 
				game->img_bgd, game->x, game->y);
			game->x = 0;
			game->y += game->charsize;
		}
		else
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win, game->img_bgd,
				game->x, game->y);
			game->x += game->charsize;
		}
	}
	game->x = 0;
	game->y = 0;
	return (0);
}

int	draw_wall(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->num_positions_1)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win, game->img_wall,
			game->positions_1[i].x * game->charsize, game->positions_1[i].y
			* game->charsize);
		i++;
	}
	return (0);
}

int	draw_collect(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->num_positions_c)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win, game->img_ball,
			game->positions_c[i].x * game->charsize, game->positions_c[i].y
			* game->charsize);
		i++;
	}
	return (0);
}

int	draw_exit(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win, game->img_exit,
		game->positions_e[0].x * game->charsize, game->positions_e[0].y
		* game->charsize);
	return (0);
}

int	draw_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win, game->img_playerr,
		game->positions_p[0].x * game->charsize, game->positions_p[0].y
		* game->charsize);
	return (0);
}
