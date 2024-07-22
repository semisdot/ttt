#ifndef GAME_STRUCT_H
#define GAME_STRUCT_H

/* ---------------------------------------------------------------------------------------------------- */

#include <stdint.h> // uint8_t

#include "game.conf.h"

/* ---------------------------------------------------------------------------------------------------- */

#define MAX_PLAYERS 2

/* ---------------------------------------------------------------------------------------------------- */

enum
{
	N_PERFORMED = 0,
	PERFORMED
};

enum
{
	N_DETERMINED = 0,
	DRAW,
	WIN
};

enum
{
	GRID_BACKGROUND_COLOR,
	GRID_LINE_COLOR,
	GRID_COLORS
};

struct RGB_Color
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
};

struct grid_position
{
	int row, col;
};

struct move_info
{
	int move_status;
	int game_status;
};

struct Player
{
	struct RGB_Color color;
};

struct Grid
{
	struct Player *cells[GRID_ROWS][GRID_COLUMNS]; // tiles/rects

	int rect_count;

	struct RGB_Color colors[GRID_COLORS];
};

struct Game
{
	struct Grid grid;

	struct Player players[MAX_PLAYERS];

	struct Player *starting_player;
	struct Player *active_player;
	// struct Player *winner_player;
};

/* ---------------------------------------------------------------------------------------------------- */

#endif // GAME_STRUCT_H
