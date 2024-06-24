#include <SDL2/SDL.h>

#include "stage1.h"
#include "stage2.h"

#include "game.h"
#include "player.h"

/* ---------------------------------------------------------------------------------------------------- */

static void logic(struct application *app);
// static void draw(struct application *app);

static void mouse_to_grid(struct Events *events, int *row, int *col);
// static void keyboard_to_grid(struct Events *events, int *row, int *col);

/* ---------------------------------------------------------------------------------------------------- */

void init_stage1(struct application *app)
{
	app->delegate.logic = logic;
	// app->delegate.draw = draw;

	// clear events
	memset(app->events.mouse.buttons, 0, sizeof(app->events.mouse.buttons[0]) * MAX_MOUSE_BUTTONS);

	// memset(app->game.grid, 0, sizeof(app->game.grid[0][0]) * MAX_GRID_CELLS);
}

/* ---------------------------------------------------------------------------------------------------- */

static void logic(struct application *app)
{
	if (app->events.mouse.buttons[SDL_BUTTON_LEFT])
	{
		int row, col;

		mouse_to_grid(&app->events, &row, &col);

		if (game_move(&app->game, row, col))
		{
			if (game_status(&app->game, row, col))
			{
				next_active_player(&app->game);
			}
			else
			{
				init_stage2(app);
			}
		}

		app->events.mouse.buttons[SDL_BUTTON_LEFT] = 0;
	}
}

static void mouse_to_grid(struct Events *events, int *row, int *col)
{
	// grid size == window size
	*row = events->mouse.y / CELL_WIDTH;
	*col = events->mouse.x / CELL_HEIGHT;
}
