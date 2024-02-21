/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typecheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkalkan <emkalkan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:11:01 by emkalkan          #+#    #+#             */
/*   Updated: 2024/02/21 15:05:32 by emkalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	number_of_lines(const char *file_path)
{
	int		fd;
	int		num_lines;
	char	*line;

	num_lines = 0;
	fd = open(file_path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		num_lines++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (num_lines);
}

void	set_positions(t_game *game, char buffer, int current_width, int height)
{
	if (buffer == '0')
	{
		game->positions_0[game->num_positions_0].x = current_width;
		game->positions_0[game->num_positions_0].y = height;
		game->num_positions_0++;
	}
	else if (buffer == '1')
	{
		game->positions_1[game->num_positions_1].x = current_width;
		game->positions_1[game->num_positions_1].y = height;
		game->num_positions_1++;
	}
	else if (buffer == 'E')
	{
		game->positions_e[game->num_positions_e].x = current_width;
		game->positions_e[game->num_positions_e].y = height;
		game->num_positions_e++;
	}
	else if (buffer == 'P')
	{
		game->positions_p[game->num_positions_p].x = current_width;
		game->positions_p[game->num_positions_p].y = height;
		game->num_positions_p++;
	}
	else if (buffer == 'C')
	{
		game->positions_c[game->num_positions_c].x = current_width;
		game->positions_c[game->num_positions_c].y = height;
		game->num_positions_c++;
		game->ballcount++;
	}
}

int	typecheck(const char *file_path, t_game *game)
{
	int		map_fd;
	int		width;
	int		height;
	int		current_width;
	char	*line;
	char	*tmp;
	char	buffer;

	map_fd = open(file_path, O_RDONLY);
	if (map_fd == -1)
	{
		ft_printf("Error opening file\n");
		return (1);
	}
	game->map = malloc(sizeof(char *) * (number_of_lines(file_path) + 1));
	if (!game->map)
	{
		ft_printf("Error allocating memory for map\n");
		free(game);
		return (EXIT_FAILURE);
	}
	width = 0;
	height = 0;
	tmp = get_next_line(map_fd);
	while (tmp != NULL)
	{
		line = ft_strtrim(tmp, "\n");
		if (!line)
		{
			ft_printf("Error in strtrim function\n");
			return (1);
		}
		free(tmp);
		game->map[height] = line;
		current_width = 0;
		while ((buffer = line[current_width]) != '\0')
			set_positions(game, buffer, current_width++, height);
		if (current_width > width)
			width = current_width;
		height++;
		tmp = get_next_line(map_fd);
	}
	free(tmp);
	if (height == 0)
	{
		close(map_fd);
		return (EXIT_FAILURE);
	}
	game->map[height] = NULL;
	while (game->num_positions_1 < MAX_ELEMENTS)
	{
		game->positions_1[game->num_positions_1].x = -1;
		game->positions_1[game->num_positions_1].y = -1;
		game->num_positions_1++;
	}
	while (game->num_positions_0 < MAX_ELEMENTS)
	{
		game->positions_0[game->num_positions_0].x = -1;
		game->positions_0[game->num_positions_0].y = -1;
		game->num_positions_0++;
	}
	while (game->num_positions_c < MAX_ELEMENTS)
	{
		game->positions_c[game->num_positions_c].x = -1;
		game->positions_c[game->num_positions_c].y = -1;
		game->num_positions_c++;
	}
	close(map_fd);
	game->bgx = width;
	game->bgy = height;
	return (0);
}
