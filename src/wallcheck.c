/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallcheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkalkan <emkalkan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 02:12:34 by emkalkan          #+#    #+#             */
/*   Updated: 2024/02/16 00:10:55 by emkalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	all_ones(char *s, int strlen)
{
	int	i;

	i = 0;
	while (i < strlen)
	{
		if (s[i] != '1')
			return (1);
		i++;
	}
	if (s[i] != '\0')
		return (1);
	return (0);
}

int	first_and_last_ones(char *s, int strlenx)
{
	if (s[0] != '1' || s[strlenx - 1] != '1')
		return (1);
	else
		return (0);
}

int	map_check_walls_outside(t_game *game)
{
	int	row;

	row = 0;
	while (row < game->bgy)
	{
		if (row == 0 || row == game->bgy - 1)
		{
			if (all_ones(game->map[row], game->bgx) != 0)
			{
				ft_printf("Error in all_ones\n");
				return (1);
			}
		}
		else
		{
			if (first_and_last_ones(game->map[row], game->bgx) != 0)
			{
				ft_printf("Error in first_and_last_ones\n");
				return (1);
			}
		}
		row++;
	}
	return (0);
}
