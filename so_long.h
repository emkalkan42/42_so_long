/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkalkan <emkalkan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:10:57 by emkalkan          #+#    #+#             */
/*   Updated: 2024/02/07 17:01:55 by emkalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 1
# define MAX_ELEMENTS 100
# define MAX_BALLS 42

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libs/libft/libft.h"
# include "libs/libx/mlx.h"

typedef struct s_position
{
    int x;
    int y;
} t_position;

typedef struct s_game 
{
	void	*mlx_ptr;
	void	*win;
	void	*img_playerr;
	void	*img_playerl;
	void	*img_playerf;
	void	*img_playerb;
	void	*img_bgd;
	void	*img_wall;
	void	*img_ball;
	void	*img_exit;
	int		charsize;
	int		ppostionx;
	int		ppostiony;
	int		cpostionx;
	int		cpostiony;
	int		epostionx;
	int		epostiony;
	int		x;
	int		y;
	int		bgx;
	int		bgy;
	int		ballcount;
	int		collectedcount;
    int collected_flags[MAX_BALLS];
    int collected_count;
	char **map;
	char **mapcopy;
	int count;
	int checklines;

    t_position positions_0[MAX_ELEMENTS];
    int num_positions_0;

    t_position positions_1[MAX_ELEMENTS];
    int num_positions_1;

    t_position positions_C[MAX_ELEMENTS];
    int num_positions_C;

	t_position positions_E[1];
	int num_positions_E;
	
    t_position positions_P[1];  
    int num_positions_P;
} t_game;

int movement(int keycode, t_game *game);
int draw_backgroundx(t_game *game);
int draw_wall(t_game *game);
int draw_player(t_game *game);
int draw_collect(t_game *game);
int draw_exit(t_game *game);
void init_and_loop(t_game *game);
int typecheck(const char *file_path, t_game *game);
int	ft_strlen2d(char **s);
int first_and_last_ones(char *s, int strlenx);
int all_ones(char *s, int strlen);
int map_check_walls_outside(t_game *game);
int floodfill(t_game *game);

#endif
