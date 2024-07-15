#include <SDL2/SDL.h>

#include "stage.game-over.h"
#include "stage.play.h"

#include "player.h"

/* ---------------------------------------------------------------------------------------------------- */

static void logic(struct application *app);
// static void draw(struct application *app);

/* ---------------------------------------------------------------------------------------------------- */

void init_stage_game_over(struct application *app)
{
	app->delegate.logic = logic;
	// app->delegate.draw = draw;

	// clear events
	memset(app->events.mouse.buttons, 0, sizeof(app->events.mouse.buttons[0]) * MAX_MOUSE_BUTTONS);
}

/* ---------------------------------------------------------------------------------------------------- */

static void logic(struct application *app)
{
	if (app->events.mouse.buttons[SDL_BUTTON_RIGHT])
	{
		next_starting_player(&app->game);

		init_stage_play(app);
	}
}
