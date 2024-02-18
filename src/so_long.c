/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkalkan <emkalkan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:10:52 by emkalkan          #+#    #+#             */
/*   Updated: 2024/02/18 17:57:20 by emkalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// 5. edge cases file names and all
	// 5.1 .ber DONE
	// 5.2 no exit DONE
	// 5.3 no player DONE
	// 5.4 no collectible DONE
	// 5.5 no wall DONE FLOOTFILL
	// 5.6 no map
	// 5.7 no file
	// 5.8 not rectangular
	// 5.9 no valid map
	// 5.10 unknown character
	// 5.11 multiple players
	// 5.12 multiple exits
// 6. norminette
void	movehelp(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win, game->img_bgd, game->x,
		game->y);
	game->count++;
	ft_printf("Movement: (%d)\n", game->count);
}

int	wallcheck(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	x /= game->charsize;
	y /= game->charsize;
	while (i < MAX_ELEMENTS)
	{
		if (game->positions_1[i].x == x && game->positions_1[i].y == y)
			return (1);
		i++;
	}
	return (0);
}

int	movement(int keycode, t_game *game) // MOVEMENT //23 lines
{
	if (keycode == 100 && !wallcheck(game, game->x + game->charsize, game->y))
	{ // RIGHT
		movehelp(game);
		game->x += game->charsize;
		mlx_put_image_to_window(game->mlx_ptr, game->win, game->img_playerr,
			game->x, game->y);
	}
	if (keycode == 97 && !wallcheck(game, game->x - game->charsize, game->y))
	{ // LEFT
		movehelp(game);
		game->x -= game->charsize;
		mlx_put_image_to_window(game->mlx_ptr, game->win, game->img_playerl,
			game->x, game->y);
	}
	if (keycode == 119 && !wallcheck(game, game->x, game->y - game->charsize))
	{ // UP
		movehelp(game);
		game->y -= game->charsize;
		mlx_put_image_to_window(game->mlx_ptr, game->win, game->img_playerb,
			game->x, game->y);
	}
	if (keycode == 115 && !wallcheck(game, game->x, game->y + game->charsize))
	{ // DOWN
		movehelp(game);
		game->y += game->charsize;
		mlx_put_image_to_window(game->mlx_ptr, game->win, game->img_playerf,
			game->x, game->y);
	}
	if (keycode == 65307)
	{
		ft_printf("Window has been closed\n");
		free_game(game);
		exit(EXIT_SUCCESS);
	}

	if (game->x == game->positions_e[0].x * game->charsize
		&& game->y == game->positions_e[0].y * game->charsize
		&& game->collectedcount > game->ballcount)
	{
		ft_printf("You Won\n");
		free_game(game);
		exit(EXIT_SUCCESS);
	}
	else
		mlx_put_image_to_window(game->mlx_ptr, game->win, game->img_exit,
			game->positions_e[0].x * game->charsize, game->positions_e[0].y
			* game->charsize);
	int ib = 0;
	while (ib < game->num_positions_c)
	{
		if (!game->collected_flags[ib] && game->x == game->positions_c[ib].x
			* game->charsize && game->y == game->positions_c[ib].y
			* game->charsize)
		{
			ft_printf("Collected\n");
			game->collected_flags[ib] = 1;
			++game->collectedcount;
		}
		ib++;
	}
	return (0);
}

void	draw_all(t_game *game)
{
	loadimg(game);
	draw_backgroundx(game);
	draw_wall(game);
	draw_collect(game);
	draw_exit(game);
	draw_player(game);
}

void	init_and_loop(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->charsize = 51;
	game->collectedcount = 1;
	game->tmp_collectible_count = game->ballcount;
	game->win = mlx_new_window(game->mlx_ptr, game->bgx * game->charsize,
			game->bgy * game->charsize, "Dragon Ball");
	error3(game);
	error1(game);
	error2(game);
	draw_all(game);
	game->x = game->positions_p[0].x * game->charsize;
	game->y = game->positions_p[0].y * game->charsize;
	mlx_key_hook(game->win, &movement, game);
	mlx_loop(game->mlx_ptr);
}

int main(int argc, char *argv[])
{
    t_game      *game;
    const char  *filename;

    if (argc != 2)
    {
        ft_printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    filename = argv[1];
    game = calloc(1, sizeof(t_game));
    if (!game)
    {
        ft_printf("Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    if (typecheck(filename, game) != 0)
    {
        ft_printf("Error in typecheck function\n");
        free(game);
        return EXIT_FAILURE;
    }

    if (check_file_format(filename) != 1)
    {
        ft_printf("Error: Incorrect file format\n");
        free(game);
        return EXIT_FAILURE;
    }

    init_and_loop(game);
    free(game);
    return EXIT_SUCCESS;
}
