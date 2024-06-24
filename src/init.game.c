#include <string.h> // memset()

#include "init.game.h"

#include "player.h"

/* ---------------------------------------------------------------------------------------------------- */

void init_game(struct Game *game)
{
	init_player_colors(game->players);

	memset(game->grid, 0, sizeof(game->grid[0][0]) * MAX_GRID_CELLS);

	init_starting_player(game);
}
