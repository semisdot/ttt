#include <SDL2/SDL.h>

#include "init.sdl.h"
#include "init.game.h"

#include "stage.play.h"

#include "input.h"
#include "draw.h"

#include "app.struct.h"

/* ---------------------------------------------------------------------------------------------------- */

#define FPS				30 // ~
#define MS_PER_FRAME	(1000 / FPS)

/* ---------------------------------------------------------------------------------------------------- */

static void frame_rate(long *elapsed);

static void clear(struct SDL *sdl);
static void present(struct SDL *sdl);

/* ---------------------------------------------------------------------------------------------------- */

int main(void)
{
	struct application app;

	init_SDL(&app.sdl);
	init_game(&app.game);
	init_stage_play(&app);

	long elapsed = SDL_GetTicks();

	while (1) // main loop
	{
		clear(&app.sdl);

		input(&app.events);

		app.stage.logic(&app);

		draw(&app.sdl, &app.game);

		present(&app.sdl);

		frame_rate(&elapsed);
	}

	return 0;
}

/* ---------------------------------------------------------------------------------------------------- */

static void frame_rate(long *elapsed)
{
	long frame_time;
	long delay_time;

	frame_time = SDL_GetTicks() - *elapsed;
	delay_time = MS_PER_FRAME - frame_time;

	if (delay_time > 0)
	{
		SDL_Delay(delay_time);
	}

	*elapsed = SDL_GetTicks();
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
