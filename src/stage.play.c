#include <SDL2/SDL.h>

#include "stage.play.h"
#include "stage.game-over.h"

#include "game.h"
#include "player.h"

/* ---------------------------------------------------------------------------------------------------- */

static void logic(struct application *app);
// static void draw(struct application *app);

static void mouse_to_grid(struct Events *events, struct grid_position *pos);
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
		struct grid_position pos;
		struct move_info info;

		memset(&info, 0, sizeof(info));

		mouse_to_grid(&app->events, &pos);

		game_move(&app->game, &pos, &info);

		if (info.move_status == PERFORMED)
		{
			game_status(&app->game, &pos, &info);

			if (info.game_status == N_DETERMINED)
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

static void mouse_to_grid(struct Events *events, struct grid_position *pos)
{
	// grid size == window size
	pos->row = events->mouse.y / CELL_WIDTH;
	pos->col = events->mouse.x / CELL_HEIGHT;
}
