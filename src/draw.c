/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkalkan <emkalkan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:28:40 by emkalkan          #+#    #+#             */
/*   Updated: 2024/02/16 00:11:17 by emkalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	draw_backgroundx(t_game *game) // 17 lines
{
	while (game->x < game->charsize * game->bgx && game->y < game->charsize
		* game->bgy)
		if (game->x >= game->charsize * game->bgx - game->charsize)
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win, game->img_bgd,
				game->x, game->y);
			game->x = 0;
			game->y += game->charsize;
		}
		else
		{
			mlx_put_image_to_window(game->mlx_ptr, game->win, game->img_bgd,
				game->x, game->y);
			game->x += game->charsize;
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
	while (i < game->num_positions_C)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win, game->img_ball,
			game->positions_C[i].x * game->charsize, game->positions_C[i].y
			* game->charsize);
		i++;
	}
	return (0);
}

int	draw_exit(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win, game->img_exit,
		game->positions_E[0].x * game->charsize, game->positions_E[0].y
		* game->charsize);
	return (0);
}

int	draw_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win, game->img_playerr,
		game->positions_P[0].x * game->charsize, game->positions_P[0].y
		* game->charsize);
	return (0);
}

void	loadimg(t_game *game)
{
	game->img_playerr = mlx_xpm_file_to_image(game->mlx_ptr, "img/playerr.xpm",
			&game->charsize, &game->charsize);
	game->img_playerl = mlx_xpm_file_to_image(game->mlx_ptr, "img/playerl.xpm",
			&game->charsize, &game->charsize);
	game->img_playerf = mlx_xpm_file_to_image(game->mlx_ptr, "img/playerf.xpm",
			&game->charsize, &game->charsize);
	game->img_playerb = mlx_xpm_file_to_image(game->mlx_ptr, "img/playerb.xpm",
			&game->charsize, &game->charsize);
	game->img_bgd = mlx_xpm_file_to_image(game->mlx_ptr, "img/background.xpm",
			&game->charsize, &game->charsize);
	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr, "img/wall.xpm",
			&game->charsize, &game->charsize);
	game->img_ball = mlx_xpm_file_to_image(game->mlx_ptr, "img/ball.xpm",
			&game->charsize, &game->charsize);
	game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr, "img/exit.xpm",
			&game->charsize, &game->charsize);
	if (!game->img_playerr || !game->img_playerl || !game->img_playerf
		|| !game->img_playerb || !game->img_bgd || !game->img_wall
		|| !game->img_ball || !game->img_exit)
	{
		ft_printf("Error loading image\n");
		exit(EXIT_FAILURE);
	}
}
