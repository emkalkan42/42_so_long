#include "../so_long.h"

void	free_map(t_game *game, char **map_version)
{
	int	i;

	i = 0;
	while (i < game->bgy)
	{
		free(map_version[i]);
		i++;
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
	// free(game->positions_1);
	// free(game->positions_c);
	// free(game->positions_e);
	// free(game->positions_p);
	// free(game->img_bgd);
	// free(game->img_wall);
	// free(game->img_ball);
	// free(game->img_exit);
	// free(game->img_playerr);
	mlx_destroy_image(game->mlx_ptr, game->img_bgd);
	mlx_destroy_image(game->mlx_ptr, game->img_wall);
	mlx_destroy_image(game->mlx_ptr, game->img_ball);
	mlx_destroy_image(game->mlx_ptr, game->img_exit);
	mlx_destroy_image(game->mlx_ptr, game->img_playerr);
	mlx_destroy_image(game->mlx_ptr, game->img_playerl);
	mlx_destroy_image(game->mlx_ptr, game->img_playerf);
	mlx_destroy_image(game->mlx_ptr, game->img_playerb);
	free_map(game, game->map);
	mlx_destroy_window(game->mlx_ptr, game->win);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free(game);
}

void	free_gamechars(t_game *game)
{
	free_map(game, game->map);
	mlx_destroy_window(game->mlx_ptr, game->win);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free(game);
}
