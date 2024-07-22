#include <SDL2/SDL.h>

#include "init.sdl.h"
#include "init.game.h"

#include "stage.play.h"

#include "input.h"
#include "draw.h"

#include "app.struct.h"

/* ---------------------------------------------------------------------------------------------------- */

#define FPS				30 // ~
#define MS_PER_FRAME	(1000.0 / FPS)

/* ---------------------------------------------------------------------------------------------------- */

static void frame_rate(long *last_time);

static void clear(struct SDL *sdl);
static void present(struct SDL *sdl);

/* ---------------------------------------------------------------------------------------------------- */

int main(void)
{
	struct application app;

	init_SDL(&app.sdl);
	init_game(&app.game);
	init_stage_play(&app);

	long last_time = SDL_GetTicks();

	while (1) // main loop
	{
		clear(&app.sdl);

		input(&app.events);

		app.stage.logic(&app);

		draw(&app.sdl, &app.game);

		present(&app.sdl);

		frame_rate(&last_time);
	}

	return 0;
}

/* ---------------------------------------------------------------------------------------------------- */

static void frame_rate(long *last_time)
{
	static float remainder = 0.0;

	long current_time;
	long frame_time;
	long delay_time;

	remainder += MS_PER_FRAME - (int)MS_PER_FRAME;
	delay_time = MS_PER_FRAME + remainder;

	current_time = SDL_GetTicks();

	frame_time = current_time - *last_time;
	delay_time -= frame_time;

	if (delay_time > 0)
	{
		SDL_Delay(delay_time);
	}

	remainder -= (int)remainder;

	*last_time = SDL_GetTicks();
}

static void clear(struct SDL *sdl)
{
	SDL_SetRenderDrawColor(sdl->renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(sdl->renderer);
}

static void present(struct SDL *sdl)
{
	SDL_RenderPresent(sdl->renderer);
}
