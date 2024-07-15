#include <string.h> // memset()

#include "init.game.h"

#include "player.h"

/* ---------------------------------------------------------------------------------------------------- */

static void init_player_colors(struct Player *players);
static void init_grid_colors(struct Grid *grid);

/* ---------------------------------------------------------------------------------------------------- */

void init_game(struct Game *game)
{
	init_player_colors(&game->players[0]);
	init_grid_colors(&game->grid);

	// memset(game->grid.cells, 0, sizeof(game->grid.cells[0][0]) * MAX_GRID_CELLS);

	init_starting_player(game);
}

static void init_player_colors(struct Player *players)
{
	const struct RGB_Color player_colors[MAX_PLAYERS] =
	{
		{0, 0, 255},
		{255, 0, 0}
	};

	int i;

	for (i = 0; i < MAX_PLAYERS; ++i)
	{
		players[i].rect_color = player_colors[i];
	}
}

static void init_grid_colors(struct Grid *grid)
{
	enum
	{
		GRID_BACKGROUND_COLOR,
		GRID_LINE_COLOR
	};

	const struct RGB_Color grid_colors[] =
	{
		{0, 0, 0},
		{128, 128, 128}
	};

	grid->background_color	= grid_colors[GRID_BACKGROUND_COLOR	];
	grid->line_color		= grid_colors[GRID_LINE_COLOR		];
}
