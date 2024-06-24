#ifndef GAME_STRUCT_H
#define GAME_STRUCT_H

/* ---------------------------------------------------------------------------------------------------- */

#include <stdint.h> // uint8_t

#include "game.conf.h"

/* ---------------------------------------------------------------------------------------------------- */

#define MAX_PLAYERS 2

/* ---------------------------------------------------------------------------------------------------- */

struct RGB_Color
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
};

struct Player
{
	struct RGB_Color rect_color;

	// <struct int row, col> rects[MAX_PLAYER_RECTS];
	// int rect_count;
};

#if 0
struct Grid
{
	// SDL_Point point OR SDL_Rect rect/window

	// struct RGB_Color background_color;

	struct Player *cells[GRID_ROWS][GRID_COLUMNS]; // tiles/rects
};
#endif

struct Game
{
	struct Player *grid[GRID_ROWS][GRID_COLUMNS];

	struct Player players[MAX_PLAYERS];

	struct Player *starting_player;
	struct Player *active_player;
	// struct Player *winner_player;
};

/* ---------------------------------------------------------------------------------------------------- */

#endif // GAME_STRUCT_H
