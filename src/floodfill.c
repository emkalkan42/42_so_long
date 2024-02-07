#include "../so_long.h"

void copymap(t_game *game)
{
	ft_strdup(game->map) opy;
}

void move(t_game *game, int x, int y, int coins, int exit)
{
	int coinscollected;
	int exitcollected;

	exitcollected = 0;
	coinscollected = 0;

	while (coins < coinscollected && exit < exitcollected)
	{
		if (game->map[x + 1] != 1 || game->map[x + 1]  != '@')
		{
			x++;
			x = '@';
		}
		if (game->map[y + 1] != 1 || game->map[y + 1]  != '@')
		{
			y++;
			y = '@';
		}
		if (game->map[x - 1] != 1 || game->map[x - 1]  != '@')
		{
			x--;
			x = '@';
		}
		if (game->map[y - 1] != 1 || game->map[y - 1]  != '@')
		{
			y--;
			y = '@';
		}
	}
}

int floodfill(t_game *game)
{

	if (move(game, game->positions_P[0].x, game->positions_P[0].y, game->ballcount, 1))
	{

	}

}
