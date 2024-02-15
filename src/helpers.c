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

void	free_game(t_game *game)
{
	// free(game->positions_0);
	// free(game->positions_1);
	// free(game->positions_C);
	// free(game->positions_E);
	// free(game->positions_P);
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
	// free_map(game, game->map_tmp);
	mlx_destroy_window(game->mlx_ptr, game->win);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free(game);
}
