/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typecheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkalkan <emkalkan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:11:01 by emkalkan          #+#    #+#             */
/*   Updated: 2024/02/21 14:50:31 by emkalkan         ###   ########.fr       */
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
	if (!line)
	{
		close(fd);
		return (0);
	}
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
		if (game->num_positions_e > 0)
		{
			printf("ERROR: MORE THEN 1 EXIT\n");
			free_map(game->map, height);
			free(game->mlx_ptr);
			free(game);
			exit(EXIT_FAILURE);
		}
		game->positions_e[game->num_positions_e].x = current_width;
		game->positions_e[game->num_positions_e].y = height;
		game->num_positions_e++;
	}
	else if (buffer == 'P')
	{
		if (game->num_positions_p > 0)
		{
			printf("ERROR: MORE THEN 1 PLAYER\n");
			free_map(game->map, height);
			free(game->mlx_ptr);
			free(game);
			exit(EXIT_FAILURE);
		}
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
	else
	{
		ft_printf("Error: Invalid character '%c' found in the map.\n", buffer);
		if (game->map != NULL)
			free_map(game->map, height);
		free(game->mlx_ptr);
		free(game);
		exit(EXIT_FAILURE);
	}
}

int	typecheck(const char *file_path, t_game *game)
{
	int		map_fd;
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
		close(map_fd);
		return (EXIT_FAILURE);
	}
	game->bgx = 0;
	game->bgy = 0;
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
		game->map[game->bgy] = line;
		current_width = 0;
		while ((buffer = line[current_width]) != '\0')
			set_positions(game, buffer, current_width++, game->bgy);
		if (current_width > game->bgx)
			game->bgx = current_width;
		game->bgy++;
		tmp = get_next_line(map_fd);
	}
	free(tmp);
	if (game->bgy == 0)
	{
		close(map_fd);
		return (EXIT_FAILURE);
	}
	game->map[game->bgy] = NULL;
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
	if (game->ballcount == 0)
	{
		ft_printf("Error: No collectible found in the map.\n");
		free_map(game->map, game->bgy);
		free(game->mlx_ptr);
		free(game);
		exit (EXIT_FAILURE);
	}
	game->bgx = game->bgx;
	game->bgy = game->bgy;
	return (0);
}
