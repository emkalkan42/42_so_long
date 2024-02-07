/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkalkan <emkalkan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:10:52 by emkalkan          #+#    #+#             */
/*   Updated: 2024/02/06 17:57:52 by emkalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


//1. check if the map is surounded by 1XXXXXX
//2. check if the map is possible
//3. destroy all images for still reacheable fail
//4. exit image if on player is gone
//5. edge cases file names and all
//6. norminette
void movehelp(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win, game->img_bgd, game->x, game->y);
	game->count++;
	ft_printf("Movement: (%d)\n", game->count);
}

int wallcheck(t_game *game, int x, int y)
{
	int i;

	i = 0;

	x /= game->charsize;
	y /= game->charsize;

	while(i < MAX_ELEMENTS)
	{
		if (game->positions_1[i].x == x && game->positions_1[i].y == y)
			return 1;
		i++;
	}
	return 0;
}

int movement(int keycode, t_game *game) //MOVEMENT //23 lines
{
	if (keycode == 100 && !wallcheck(game, game->x + game->charsize, game->y)) { // RIGHT
		movehelp(game);
		game->x += game->charsize;
		mlx_put_image_to_window(game->mlx_ptr, game->win, game->img_playerr, game->x, game->y);
	}
	if (keycode == 97 && !wallcheck(game, game->x - game->charsize, game->y)) { //LEFT
		movehelp(game);
		game->x -= game->charsize;
		mlx_put_image_to_window(game->mlx_ptr, game->win, game->img_playerl, game->x, game->y);
	}
	if (keycode == 119 && !wallcheck(game, game->x, game->y - game->charsize)) { //UP
		movehelp(game);
		game->y -= game->charsize;
		mlx_put_image_to_window(game->mlx_ptr, game->win, game->img_playerb, game->x, game->y);
	}
	if (keycode == 115  && !wallcheck(game, game->x, game->y + game->charsize)) { //DOWN
		movehelp(game);
		game->y += game->charsize;
		mlx_put_image_to_window(game->mlx_ptr, game->win, game->img_playerf, game->x, game->y);
	}
	if (keycode == 65307) {
    ft_printf("Window has been closed\n");
    mlx_destroy_window(game->mlx_ptr, game->win);
    exit(EXIT_SUCCESS);
	}

	if (game->x == game->positions_E[0].x * game->charsize && game->y == game->positions_E[0].y * game->charsize && game->collectedcount > game->ballcount) {    
		ft_printf("You Won\n");
        mlx_destroy_window(game->mlx_ptr, game->win);
        exit(EXIT_SUCCESS);
	}
	else 
		mlx_put_image_to_window(game->mlx_ptr, game->win, game->img_exit, game->positions_E[0].x * game->charsize, game->positions_E[0].y * game->charsize);
	int ib = 0;
	while (ib < game->num_positions_C) {
	    if (!game->collected_flags[ib] && game->x == game->positions_C[ib].x * game->charsize && game->y == game->positions_C[ib].y * game->charsize) {
	        ft_printf("Collected\n");
	        game->collected_flags[ib] = 1;
	        ++game->collectedcount;
	    }
	    ib++;
	}
	return 0;
}

void loadimg(t_game *game)
{
	game->img_playerr = mlx_xpm_file_to_image(game->mlx_ptr, "img/playerr.xpm", &game->charsize, &game->charsize);
	game->img_playerl = mlx_xpm_file_to_image(game->mlx_ptr, "img/playerl.xpm", &game->charsize, &game->charsize);
	game->img_playerf = mlx_xpm_file_to_image(game->mlx_ptr, "img/playerf.xpm", &game->charsize, &game->charsize);
	game->img_playerb = mlx_xpm_file_to_image(game->mlx_ptr, "img/playerb.xpm", &game->charsize, &game->charsize);
	game->img_bgd = mlx_xpm_file_to_image(game->mlx_ptr, "img/background.xpm", &game->charsize, &game->charsize);
	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr, "img/wall.xpm", &game->charsize, &game->charsize);
	game->img_ball = mlx_xpm_file_to_image(game->mlx_ptr, "img/ball.xpm", &game->charsize, &game->charsize);
	game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr, "img/exit.xpm", &game->charsize, &game->charsize);
	if (!game->img_playerr || !game->img_playerl || !game->img_playerf || !game->img_playerb || !game->img_bgd || !game->img_wall || !game->img_ball || !game->img_exit)
	{
		ft_printf("Error loading image\n");
		exit(EXIT_FAILURE);
	}
}
int draw_backgroundx(t_game *game) //17 lines
{
	while (game->x < game->charsize*game->bgx && game->y < game->charsize*game->bgy)
	if (game->x >= game->charsize*game->bgx - game->charsize)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win, game->img_bgd, game->x, game->y);
		game->x = 0;
		game->y += game->charsize;
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win, game->img_bgd, game->x, game->y);
		game->x += game->charsize;
	}
	game->x = 0;
	game->y = 0;
	return 0;
}

int draw_wall(t_game *game)
{
    int i = 0;
    while (i < game->num_positions_1)
    {
        mlx_put_image_to_window(game->mlx_ptr, game->win, game->img_wall, game->positions_1[i].x * game->charsize, game->positions_1[i].y * game->charsize);
        i++;
    }
    return 0;
}

int draw_collect(t_game *game)
{
    int i = 0;
    while (i < game->num_positions_C)
    {
        mlx_put_image_to_window(game->mlx_ptr, game->win, game->img_ball, game->positions_C[i].x * game->charsize, game->positions_C[i].y * game->charsize);
        i++;
    }
    return 0;
}

int draw_exit(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win, game->img_exit, game->positions_E[0].x * game->charsize, game->positions_E[0].y * game->charsize);
	return 0;
}

int draw_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win, game->img_playerr, game->positions_P[0].x * game->charsize, game->positions_P[0].y * game->charsize);
	return 0;
}

void init_and_loop(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		ft_printf("Error initializing MiniLibX\n");
		exit(EXIT_FAILURE);
	}
	ft_printf("x: %d\n", game->bgx);
	ft_printf("y: %d\n", game->bgy);
	if (game->bgx <= game->bgy)
	{
		ft_printf("Error Window not rectangular\n");
		exit(EXIT_FAILURE);
	}
	game->win = mlx_new_window(game->mlx_ptr, game->bgx * game->charsize, game->bgy * game->charsize, "Dragon Ball Z");
	if (!game->win)
	{
		ft_printf("Error creating window\n");
		exit(EXIT_FAILURE);
	}
	int i = 0;
	while (i < MAX_BALLS)
	{
	    game->collected_flags[i] = 0;
	    i++;
	}

	mlx_key_hook(game->win, &movement, game);
	loadimg(game);
	draw_backgroundx(game);
	draw_wall(game);
	draw_collect(game);
	draw_exit(game);
	game->x = game->positions_P[0].x * game->charsize;
    game->y = game->positions_P[0].y * game->charsize;
	draw_player(game);
	if (map_check_walls_outside(game) != 0)
    {
        // Handle the error or exit the program
        ft_printf("Error in map_check_walls_outside\n");
        free(game);
        exit(EXIT_FAILURE);
    }
	else     
	ft_printf("map check is good\n");
	mlx_loop(game->mlx_ptr);
}

int main(int argc, char *argv[])
{
    t_game *game;
	const char *filename;
	
	game = malloc(sizeof(t_game));
    if (argc != 2)
    {
        ft_printf("Usage: %s <filename>\n", argv[0]);
        return (EXIT_FAILURE);
    }
    filename = argv[1];
    if (typecheck(filename, game) == 1)
    {
        ft_printf("Error in typecheck function\n");
        free(game);
        return (EXIT_FAILURE);
    }
    game->charsize = 51;
    game->collectedcount = 1;

    init_and_loop(game);
    free(game);
    return (EXIT_SUCCESS);
}
