#include <SDL2/SDL.h>

#include "input.h"

/* ---------------------------------------------------------------------------------------------------- */

static void mouse_button_down(SDL_MouseButtonEvent *event, struct Mouse *mouse);
static void mouse_button_up(SDL_MouseButtonEvent *event, struct Mouse *mouse);

/* ---------------------------------------------------------------------------------------------------- */

void input(struct Events *events)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
			{
				exit(0);
				// break;
			}

			case SDL_MOUSEBUTTONDOWN:
			{
				mouse_button_down(&event.button, &events->mouse);
				break;
			}

			case SDL_MOUSEBUTTONUP:
			{
				mouse_button_up(&event.button, &events->mouse);
				break;
			}
		}
	}

	SDL_GetMouseState(&events->mouse.x, &events->mouse.y);
}

/* ---------------------------------------------------------------------------------------------------- */

static void mouse_button_down(SDL_MouseButtonEvent *event, struct Mouse *mouse)
{
	if (event->button < MAX_MOUSE_BUTTONS)
	{
		mouse->buttons[event->button] = 1;
	}
}

static void mouse_button_up(SDL_MouseButtonEvent *event, struct Mouse *mouse)
{
	if (event->button < MAX_MOUSE_BUTTONS)
	{
		mouse->buttons[event->button] = 0;
	}
}
