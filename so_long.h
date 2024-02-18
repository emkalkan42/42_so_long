/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emkalkan <emkalkan@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:10:57 by emkalkan          #+#    #+#             */
/*   Updated: 2024/02/18 17:57:44 by emkalkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 1
# define MAX_ELEMENTS 100
# define MAX_BALLS 42

# include "libs/libft/libft.h"
# include "libs/libx/mlx.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_position
{
	int			x;
	int			y;
}				t_position;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win;
	void		*img_playerr;
	void		*img_playerl;
	void		*img_playerf;
	void		*img_playerb;
	void		*img_bgd;
	void		*img_wall;
	void		*img_ball;
	void		*img_exit;
	int			charsize;
	int			ppostionx;
	int			ppostiony;
	int			x;
	int			y;
	int			bgx;
	int			bgy;
	int			collectedcount;
	int			collected_flags[MAX_BALLS];
	char		**map;
	char		**map_tmp;
	int			tmp_collectible_count;
	int			count;
	int			exits;
	int			ballcount;
	int			floodfillcount;
	int			tmp_exit_count;

	t_position	positions_0[MAX_ELEMENTS];
	int			num_positions_0;

	t_position	positions_1[MAX_ELEMENTS];
	int			num_positions_1;

	t_position	positions_c[MAX_ELEMENTS];
	int			num_positions_c;

	t_position	positions_x[MAX_ELEMENTS];
	int			num_positions_x;

	t_position	positions_e[1];
	int			num_positions_e;

	t_position	positions_p[1];
	int			num_positions_p;
}				t_game;

int				movement(int keycode, t_game *game);
int				draw_backgroundx(t_game *game);
int				draw_wall(t_game *game);
int				draw_player(t_game *game);
int				draw_collect(t_game *game);
int				draw_exit(t_game *game);
void			draw_all(t_game *game);
void			init_and_loop(t_game *game);
int				typecheck(const char *file_path, t_game *game);
int				first_and_last_ones(char *s, int strlenx);
int				all_ones(char *s, int strlen);
int				map_check_walls_outside(t_game *game);
int				find_all_collectibles(t_game *game, int x, int y);
int				find_exit(t_game *game, int x, int y);
void			free_map(t_game *game, char **map_version);
int				check_for_path(t_game *game, int x, int y);
void			intialise_tmp_map(t_game *game);
int				possible_or_not(t_game *game, int x, int y);
void			check_exit_coordinate(t_game *game, int x, int y);
void			check_collectible_coordinate(t_game *game, int x, int y);
int				possible_or_not_exit(t_game *game, int x, int y);
void			loadimg(t_game *game);
void			error1(t_game *game);
void			error2(t_game *game);
void			error3(t_game *game);
void			init_pointers(t_game *game);
void			init_integers(t_game *game);
void			init_arrays(t_game *game);
void			init_counters(t_game *game);
void			init_game(t_game *game);
void			free_game(t_game *game);
void			free_gametest(t_game *game);
int				check_file_format(const char *file_name);
void			free_gamechars(t_game *game);


#endif
