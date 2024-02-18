/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkalkan <emkalkan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 16:36:53 by emkalkan          #+#    #+#             */
/*   Updated: 2024/02/16 19:31:30 by emkalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	possible_or_not(t_game *game, int x, int y)
{
	if (game->map_tmp[x][y] != '1' && game->map_tmp[x][y] != 'X')
		return (1);
	return (0);
}

void	check_exit_coordinate(t_game *game, int x, int y)
{
	if (game->map_tmp[x][y] == 'E')
		game->tmp_exit_count++;
}

int	find_exit(t_game *game, int x, int y)
{
	if (game->map_tmp[x][y] != '1' && game->map_tmp[x][y] != 'C')
		game->map_tmp[x][y] = 'C';
	if (possible_or_not_exit(game, x + 1, y) == 1)
	{
		check_exit_coordinate(game, x + 1, y);
		find_exit(game, x + 1, y);
	}
	if (possible_or_not_exit(game, x - 1, y) == 1)
	{
		check_exit_coordinate(game, x - 1, y);
		find_exit(game, x - 1, y);
	}
	if (possible_or_not_exit(game, x, y + 1) == 1)
	{
		check_exit_coordinate(game, x, y + 1);
		find_exit(game, x, y + 1);
	}
	if (possible_or_not_exit(game, x, y - 1) == 1)
	{
		check_exit_coordinate(game, x, y - 1);
		find_exit(game, x, y - 1);
	}
	return (0);
}

void	check_collectible_coordinate(t_game *game, int x, int y)
{
	if (game->map_tmp[x][y] == 'C')
		game->tmp_collectible_count--;
}

int	find_all_collectibles(t_game *game, int x, int y)
{
	if (possible_or_not(game, x, y) == 1 && game->map_tmp[x][y] != 'E')
		game->map_tmp[x][y] = 'X';
	if (possible_or_not(game, x + 1, y) == 1)
	{
		check_collectible_coordinate(game, x + 1, y);
		find_all_collectibles(game, x + 1, y);
	}
	if (possible_or_not(game, x - 1, y) == 1)
	{
		check_collectible_coordinate(game, x - 1, y);
		find_all_collectibles(game, x - 1, y);
	}
	if (possible_or_not(game, x, y + 1) == 1)
	{
		check_collectible_coordinate(game, x, y + 1);
		find_all_collectibles(game, x, y + 1);
	}
	if (possible_or_not(game, x, y - 1) == 1)
	{
		check_collectible_coordinate(game, x, y - 1);
		find_all_collectibles(game, x, y - 1);
	}
	return (0);
}
