/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkalkan <emkalkan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 23:53:02 by emkalkan          #+#    #+#             */
/*   Updated: 2024/02/21 14:50:10 by emkalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(char **map_version, int height)
{
	int	i;

	if (height != -1)
	{
		while (height >= 0)
		{
			free(map_version[height]);
			height--;
		}
	}
	else
	{
		i = 0;
		while (map_version[i])
		{
			free(map_version[i]);
			i++;
		}
	}
	free(map_version);
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

void	free_game(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->img_bgd);
	mlx_destroy_image(game->mlx_ptr, game->img_wall);
	mlx_destroy_image(game->mlx_ptr, game->img_ball);
	mlx_destroy_image(game->mlx_ptr, game->img_exit);
	mlx_destroy_image(game->mlx_ptr, game->img_playerr);
	mlx_destroy_image(game->mlx_ptr, game->img_playerl);
	mlx_destroy_image(game->mlx_ptr, game->img_playerf);
	mlx_destroy_image(game->mlx_ptr, game->img_playerb);
	free_map(game->map, -1);
	mlx_destroy_window(game->mlx_ptr, game->win);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free(game);
}

void	free_gamechars(t_game *game)
{
	free_map(game->map, -1);
	mlx_destroy_window(game->mlx_ptr, game->win);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free(game);
}
