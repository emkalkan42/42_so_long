/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkalkan <emkalkan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:58:01 by emkalkan          #+#    #+#             */
/*   Updated: 2024/02/18 22:04:39 by emkalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	intialise_tmp_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->map_tmp = (char **)malloc(game->bgy * sizeof(char *));
	while (y < game->bgy)
	{
		game->map_tmp[y] = (char *)malloc((game->bgx + 1) * sizeof(char));
		x = 0;
		while (x < game->bgx)
		{
			game->map_tmp[y][x] = game->map[y][x];
			if (game->map_tmp[y][x] == 'P')
			{
				game->ppostionx = y;
				game->ppostiony = x;
			}
			x++;
		}
		game->map_tmp[y][x] = '\0';
		y++;
	}
}

void	printcurrentmap(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->bgy)
	{
		x = 0;
		while (x < game->bgx)
		{
			x++;
		}
		ft_printf("| %s |\n",game->map_tmp[y]);
		y++;
	}
	usleep(25000);
}
int	possible_or_not_exit(t_game *game, int x, int y)
{
	if (game->map_tmp[x][y] != '1' && game->map_tmp[x][y] != 'C'
		&& game->map_tmp[x][y] != 'F')
	{
		return (1);
	}
	return (0);
}


int	check_for_path(t_game *game, int x, int y)
{
	intialise_tmp_map(game);
	find_all_collectibles(game, y, x);
	find_exit(game, y, x);
	if (game->tmp_collectible_count == 0)
	{
		if (game->tmp_exit_count > 0)
		{
			ft_printf("Map passed all checks. Game is launching... \n");
			free_map(game->map_tmp);
			return (1);
		}
		else
		{
			ft_printf("ERROR PATH EXIT\n");
			free_map(game->map_tmp);
			mlx_destroy_window(game->mlx_ptr, game->win);
			return (0);
		}
	}
	else
	{
		ft_printf("ERROR PATH COLLECTIBLES\n");
		free(game);
		exit(EXIT_FAILURE);
	}
}
