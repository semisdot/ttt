// #ifndef GAME_CONF_H
// #define GAME_CONF_H

/* ---------------------------------------------------------------------------------------------------- */

#include "sdl.conf.h"

/* ---------------------------------------------------------------------------------------------------- */

#define GRID_WIDTH		SDL_WINDOW_WIDTH
#define GRID_HEIGHT		SDL_WINDOW_HEIGHT

#define N				3

#define GRID_ROWS		N
#define GRID_COLUMNS	N

#define MAX_GRID_CELLS	(GRID_ROWS * GRID_COLUMNS)

#define CELL_WIDTH		(GRID_WIDTH / GRID_COLUMNS)
#define CELL_HEIGHT		(GRID_HEIGHT / GRID_ROWS)

/* ---------------------------------------------------------------------------------------------------- */

// #define MAX_PLAYERS		2

/* ---------------------------------------------------------------------------------------------------- */

// #endif // GAME_CONF_H
